/* ========================================
 *
 * This code controls a Cypress CY8CKIT-048 Analog Coprocessor. More info:
 * https://www.hackster.io/Abysmal/lighting-with-cypress-cy8ckit-048-c31193?team=36760
 * 
 * This project is made for "Sensing the World"
 * contest on hackster.io. More info:
 * https://www.hackster.io/contests/cypress-sensing-the-world-contest
 * 
 * author: Balázs Simon
 * e-mail: simon.balazs.1992@gmail.com
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>

/* General constants */
#define LED_ON                      (0)
#define LED_OFF                     (1)
#define ADC_CHANNEL_PIR             (0)
#define ADC_CHANNEL_POT             (1)
#define ADC_CHANNEL_MIC             (2)
/* Used to get the new PWM value for the LED_Strip. It indicates the ratio between the new and the old readings when creating the new one */
#define AVG_WEIGHT                  (0.1)

/* Constants used to clap detection */
/* The effects of a clap lasts no more than 40ms. After that it's something else */
#define CLAP_DECAY_TIME             (40)
/* There need to be at least 180ms silence between claps */
#define MIN_SILENCE_AFTER_CLAP      (180)   
/* The second clap needs to be registered in 1500ms */
#define MAX_WAITING_BETWEEN_CLAPS   (1500)
//#define AUDIO_LEVEL_WEIGHT          (0.08)
/* Audio signals examined using the last 25 readings */
#define AUDIO_WINDOW_SIZE           (25)
/* It is used to calculate the microphone values of silence */
#define NUMBER_OF_SILENCE_SAMPLES   (20)
#define MIC_DETECTION_THRESHOLD     (1600)

/* Constants used for PIR */
#define PIR_HIGH_THRESHOLD          (250)
#define PIR_LOW_THRESHOLD           (-250)

/* Constants used to calculate humidity */
/* This is the capacitance of the sensor at 55% RH with 0.1pF resolution */
#define CAPACITANCE_AT_55_RH        (1800)
/* Sensitivity numerator and denominator indicate sensitivity of the sensor */
#define SENSITIVITY_NUMERATOR       (31)
#define SENSITIVITY_DENOMINATOR     (100)
/* Value of reference capacitor.  Note that this value includes the pin capacitance
    and the physical 180pF reference capacitor */
#define CREF                        (1930)
/* Offset Capacitance */
#define COFFSET                     (150)
/* This is raw count equivalent to trace capacitance */
#define OFFSETCOUNT                 (1536)
#define BUFFERSIZE                  (8)
#define READ_WRITE_BOUNDARY         (0)
/* Nominal humidity 55% */
#define NOMINAL_HUMIDITY            (550)
#define HUMIDITY_0_PERCENT          (0)
#define HUMIDITY_100_PERCENT        (1000)
#define HUMIDITY_70                 (700)   

/* Structure that holds all the sensor values connected to the humidity sensor*/
/* Use __attribute__((packed)) for GCC and MDK compilers to pack structures      */
/* For other compilers use the corresponding directive.                          */
/* For example, for IAR use the following directive                              */
/* typedef __packed struct {..}struct_name;                                      */
typedef struct __attribute__((packed))
{
	uint16 humidityRawCounts;	/* Raw count from CapSense Component for the humidity sensor */
	uint16 capacitance;			/* Capacitance of the humidity sensor */
	uint16 humidity;			/* Measured humidity */
	uint16 rawCountsRefCap;     /* Raw count from CapSense Component for the Reference capacitor */
}humidity_sensor_data;

int audioWindow[AUDIO_WINDOW_SIZE];
int switchedOn;
int arrayIndex;
long millis;
humidity_sensor_data data = {0, 0, 0, 0};

/*******************************************************************************
* Function Name: calculateAVGSilenceSignal
********************************************************************************
*
* Summary:
* This function calculates an avarage audio level. It must be called when there's as minimal sound in the room as possible
*
* Parameters:
*  None
*
* Return:
*  Calculated average silence audio value
*
* Side Effects:
* None
*******************************************************************************/
int calculateAVGSilenceSignal(void){
    float silenceAudioLevel = 0;
    int i;
    for(i = 0; i < NUMBER_OF_SILENCE_SAMPLES; i++){
        ADC_StartConvert();
        while( ADC_IsEndConversion(ADC_RETURN_STATUS)){};
        ADC_GetResult16(ADC_CHANNEL_MIC);
        silenceAudioLevel += ADC_GetResult16(ADC_CHANNEL_MIC);
    }
        
    silenceAudioLevel /= NUMBER_OF_SILENCE_SAMPLES;
    
    return silenceAudioLevel;
}

/*******************************************************************************
* Function Name: stopAndResetTimer
********************************************************************************
*
* Summary:
* This function will stop Millis_Update_Timer and reset the variable 'millis'
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  Millis_Update_Timer will be stopped
*  millis value will be set to 0
*******************************************************************************/
void stopAndResetTimer(void){
    Millis_Update_Timer_Stop();
    millis = 0;
}

/*******************************************************************************
* Function Name: addNewReading
********************************************************************************
*
* Summary:
* This function will give the averageSilenceAudioLevel - reading value to audioWindow. audioWindow is used in a FIFO pipeline way, using the arrayIndex variable
*
* Parameters:
*  int reading - the new reading from the adc's microphone channel
*  float averageSilenceAudioLevel - the value calculated by calculateAVGSilenceSignal function
*
* Return:
*  None
*
* Side Effects:
*  An element in audioWindow array will be overwritten
*  arrayIndex will be increment by 1 or will be changed to 0 if it reaches the size of audioWindow
*******************************************************************************/
__inline void addNewReading(int reading, float averageSilenceAudioLevel){
    audioWindow[arrayIndex] = (int)averageSilenceAudioLevel - reading;
    //averageSilenceAudioLevel = averageSilenceAudioLevel * (1 - AUDIO_LEVEL_WEIGHT) + AUDIO_LEVEL_WEIGHT * reading;
    arrayIndex++;
    if(arrayIndex == AUDIO_WINDOW_SIZE){
        arrayIndex = 0;
    }
}

/*******************************************************************************
* Function Name: findEvents
********************************************************************************
*
* Summary:
* This function will give you to sum of numeric differential of audioWindow's values. It used to find high amplite impulses that might be claps
*
* Parameters:
*  None
*
* Return:
*  sum of numeric differential of audioWindow's values
*
* Side Effects:
*  None
*******************************************************************************/
__inline int findEvents(void){
    int temp = 0;
    int i;
    for(i = 0; i < AUDIO_WINDOW_SIZE - 1; i++){
        temp += abs(audioWindow[i] - audioWindow[i + 1]);
    }
    return temp;
}

/*******************************************************************************
* Function Name: __inline uint16 CalculateHumidity(uint16 Capacitance)
********************************************************************************
*
* Summary:
*  This function calculates humidity from capacitance

* Parameters:
*  uint16 Capacitance - Capacitance of the humidity sensor
*
* Return:
*  Calculated Humidity value
*
* Side Effects:
*   None
*******************************************************************************/
__inline uint16 CalculateHumidity(uint16 capacitance)
{
    int16 humidity;
    int16 delta;
    
    /* Find capacitance difference from nominal capacitance at 55% RH */
    delta = capacitance - CAPACITANCE_AT_55_RH;
    
    /* Calculate humidity from capacitance difference and sensor sensitivity */
    humidity = ((delta * SENSITIVITY_DENOMINATOR) / SENSITIVITY_NUMERATOR) + NOMINAL_HUMIDITY;
    
    /* If humidity is less than zero, limit it to 0; If humidity is greater than 1000 (100%), limit to 1000 */
    humidity = (humidity < HUMIDITY_0_PERCENT) ? HUMIDITY_0_PERCENT : (humidity > HUMIDITY_100_PERCENT) ? HUMIDITY_100_PERCENT : humidity;

    /* Return Humidity value */
    return humidity;
}

/*******************************************************************************
* Function Name: __inline uint16 CalculateCapacitance(uint16 RawCounts, uint16 RefsensorCounts)
********************************************************************************
*
* Summary:
*  This function calculates capacitance from raw count.
*
* Parameters:
*  uint16 RawCounts - Raw count corresponding to Humidity sensor
*  uint16 RefsensorCounts - Raw count corresponding to Reference capacitor
*
* Return:
*  Capacitance of the Humidity sensor
*
* Side Effects:
*   None
*******************************************************************************/
__inline uint16 CalculateCapacitance(uint16 rawCounts, uint16 refsensorCounts)
{
    return (uint16)((float)(rawCounts - OFFSETCOUNT) * (CREF - COFFSET) / (float)(refsensorCounts - OFFSETCOUNT));
}

/*******************************************************************************
* Function Name: Millis_Update_Timer_Handler
********************************************************************************
* Summary:
*  The interrupt handler for Millis_Update_Timer's capture interrupt.
*  Clears a pending Interrupt.
*  Increments the millis variable. This interrupt is not really necssary, the period of the timer 
*  could be used, but it's easier to handle or change the code if it is necessary
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*   Increments the millis variable by one
*******************************************************************************/
CY_ISR ( Millis_Update_Timer_Handler )
{
    millis++;
    Millis_Update_Timer_ClearInterrupt(Millis_Update_Timer_INTR_MASK_TC);
}

/*******************************************************************************
* Function Name: Switch_Off_Timer_Handler
********************************************************************************
* Summary:
*  The interrupt handler for Switch_Off_Timer_Handler's capture interrupt.
*  Clears a pending Interrupt.
*  This timer is running when the LED_Strip is switched on. After 5 minutes the lighting will be automatically switched off.
*  Normally some external code will reset the period to zero when movement is detected by the PIR sensor
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  Millis_Update_Timer will be stopped
*  millis value will be set to 0
*  Turns of the LED_Strip
*  Negates switchedOn value
*******************************************************************************/
CY_ISR ( Switch_Off_Timer_Handler )
{
    stopAndResetTimer();
    PWM_LED_Strip_WriteCompare(0);
    switchedOn = ~switchedOn;
    Switch_Off_Timer_ClearInterrupt(Switch_Off_Timer_INTR_MASK_TC);
}

/*******************************************************************************
* Function Name: void InitResources(void)
********************************************************************************
*
* Summary:
*  This function initializes all the hardware resources
*
* Parameters:
*  None
*
* Return:
*  None
*******************************************************************************/
void InitResources(void)
{
    ADC_Start();
    ADC_StartConvert();
    
    UART_Start();
    
    PWM_LED_Strip_Start();
    
    Switch_Off_Timer_Int_StartEx(Switch_Off_Timer_Handler);
    Millis_Update_Timer_Int_StartEx(Millis_Update_Timer_Handler);
    
    /* Start the Reference Buffer */
    RefBuffer_Start();
    
    /* Start Programmable Voltage Reference */
    PVref_Start();
    
    /* Enable Programmable Voltage Reference */
    PVref_Enable();
    
    /* Start the first stage amplifier */
    PIRAmplifierStage1_Start();
    
    /* Start the second stage amplifier (PGA) */
    PIRAmplifierStage2_Start();    
    
    /* Start CapSense Component */
    CSD_Start();
    
    LED_RED_Write(LED_OFF);
    LED_GREEN_Write(LED_OFF);
    LED_BLUE_Write(LED_OFF);
    
}

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
* This function initializes all the resources, and in an infinite loop, performs tasks 
* to controls the lighting and it sends some states of the system to a computer using UART
*
* Parameters:
*  None
*
* Return:
* int
*******************************************************************************/
int main(void)
{
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    
    /* Initialize hardware resources */
    InitResources();
    float averageSilenceAudioLevel = calculateAVGSilenceSignal();
    
    int state = 0;
    int PIRReading;
    int potReading;
    float ledStripDutyCycle = 0.0f;
    switchedOn = 0;
    millis = 0;
    arrayIndex = 0;
    
    for(;;){
        int passedTime = 0;
        
        ADC_StartConvert();
        while( ADC_IsEndConversion(ADC_RETURN_STATUS)){};
            
        addNewReading(ADC_GetResult16(ADC_CHANNEL_MIC), averageSilenceAudioLevel);
        int sum = findEvents();
        
        if(state == 0 && sum > MIC_DETECTION_THRESHOLD){
            /* an inpluse occured that is higher than the detection threshold */
            /* starting the timer to update millis variable */
            Millis_Update_Timer_Start();
            state = 1;
        }
        else if(state == 1 && millis > CLAP_DECAY_TIME){
            /* after the previous step we reset the state if we register another inpulse after 40 ms (=not clap). */
            /* After 180 ms we move on to the next step */
            /* reset means that the state variable changes to 0 and we stop the Millis_Update_Timer timer */
            if(millis > MIN_SILENCE_AFTER_CLAP + CLAP_DECAY_TIME){
                state = 2;
            }
            if(sum > MIC_DETECTION_THRESHOLD){
                state = 0;
                stopAndResetTimer();
            }
        }
        else if(state == 2){
            /* if we register another clap in 1500 ms we move on to the next step. If we don't then reset comes */
            if(sum > MIC_DETECTION_THRESHOLD){
                state = 3;
                passedTime = millis;
            }
            if(millis > MAX_WAITING_BETWEEN_CLAPS + MIN_SILENCE_AFTER_CLAP + CLAP_DECAY_TIME){
                state = 0;
                stopAndResetTimer();
            }
        }
        /* If we register an inpulse after the 40ms passed, it means it's possily not a clap so reset comes again */
        /* If we don't then it's a match, we switch on/off the Lighting and reset the state, millis, negate switchedOn and stop the timer */
        else if(state == 3 &&  millis > passedTime + CLAP_DECAY_TIME){
            if(millis > passedTime + MIN_SILENCE_AFTER_CLAP + CLAP_DECAY_TIME){
                switchedOn = !switchedOn;
                state = 0;
                stopAndResetTimer();
                if(switchedOn){
                    Switch_Off_Timer_Start(); 
                }
                else{
                    PWM_LED_Strip_WriteCompare(0);
                }
            }
            if(sum > MIC_DETECTION_THRESHOLD){
                state = 0;
                stopAndResetTimer();
            }
        }
        
        /* If the lighting is switched on then updating the brightness level based on the potentiometer and */
        /* Checking for movement with the PIR and resetting Switch_Off_Timer counter if movement is detected */
        if(switchedOn){
            
            PIRReading = ADC_GetResult16(ADC_CHANNEL_PIR);
            potReading = ADC_GetResult16(ADC_CHANNEL_POT);
            
            ledStripDutyCycle = ledStripDutyCycle * (1 - AVG_WEIGHT) + AVG_WEIGHT * (255 - potReading);
            PWM_LED_Strip_WriteCompare((int)ledStripDutyCycle);
            
            if(PIRReading > PIR_HIGH_THRESHOLD || PIRReading < PIR_LOW_THRESHOLD){
                Switch_Off_Timer_WriteCounter(0);
            }
        }
        
        if(!(CSD_IsBusy()))
        {       
            
            data.humidityRawCounts = CSD_BUTTON0_SNS0_RAW0_VALUE;
            data.rawCountsRefCap = CSD_BUTTON0_SNS1_RAW0_VALUE;
            /* Convert raw counts to capacitance */
            data.capacitance = CalculateCapacitance(data.humidityRawCounts, data.rawCountsRefCap);
            /* Calculate humidity */
                
            data.humidity = CalculateHumidity(data.capacitance);   
                
            CSD_ScanAllWidgets();  
            /*Switch on the red LED when the relative humidity is greater than 70% */
            if(data.humidity > HUMIDITY_70)
            {
                LED_RED_Write(LED_ON);
            }
            else
            {
                LED_RED_Write(LED_OFF);
            }
        }        
        
        ////////////////////
        //Sending status
        char message[8];
        sprintf(message, "%d", data.humidity);
        UART_UartPutString(message);
        UART_UartPutString(", ");
        sprintf(message, "%d", sum);
        UART_UartPutString(message);
        UART_UartPutString(", ");
        sprintf(message, "%d", (int)millis);
        UART_UartPutString(message);
        UART_UartPutString(", ");
        sprintf(message, "%d", state * 500);
        UART_UartPutString(message);
        UART_UartPutString("\n\r");
    }
}

/* [] END OF FILE */

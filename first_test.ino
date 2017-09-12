#include <adc.h>
#include <behaviors.h>
#include <constants.h>
#include <ir_remote_control.h>
#include <leds.h>
#include <mirf.h>
#include <motors.h>
#include <nRF24L01.h>
#include <ports_io.h>
#include <sensors.h>
#include <speed_control.h>
#include <spi.h>
#include <twimaster.h>
//#include <usart.h>
#include <utility.h>
#include <variables.h>

#include "/home/julianapiaz/Documentos/WiSARD_Elisa-3/termometro_Linear.c"

unsigned long int startTime = 0, endTime = 0;
unsigned char prevSelector = 0;
unsigned int i = 0;

int arrayWisard [QTD_SENSORS * N_BITS];

/* Each variable is defined by the spacial configuration nedeed. For now it is required to say how many discriminators, how big is the Input 
 and how many bits the WiSARD structure needs to constitute the patterns.
*/
WISARD w;
int numDiscriminators = 3; // For V like flocks
int inputSize = 1024;      // That depends on how the funtion is turning the output value from the arduino to the bit array.
int numBits = 4;

void setup() {

  Serial.begin(115200);
  initPeripherals();
  calibrateSensors();
  initBehaviors();
  startTime = getTime100MicroSec();  
  
  wisard_create(&w, numDiscriminators, inputSize, numBits);

}

void loop() {

  currentSelector = getSelector();	          // update selector position

  readAccelXYZ();			          // update accelerometer values to compute the angle

  computeAngle();
	
  endTime = getTime100MicroSec();
  if((endTime-startTime) >= (PAUSE_2_SEC)) {
    readBatteryLevel();			          // the battery level is updated every two seconds
			
    if(currentSelector==4 || currentSelector==5) {
      pwm_red = rand() % 255;
      pwm_green = rand() % 255;
      pwm_blue = rand() % 255;
    }    
    
    startTime = getTime100MicroSec();
  }

  handleIRRemoteCommands();

  handleRFCommands();

// alterrar a escala de saida



  Serial.print("prox: ");
  for(i=0; i<8; i++) 
    termometerCoding(proximityResult[i], &arrayWisard[i*N_BITS]);
  

  switch(currentSelector) {
    
    case 0: // motors in direct power control (no speed control)
            handleMotorsWithNoController();
            break;
             
    case 1: // obstacle avoidance enabled (the robot does not move untill commands are 
            // received from the radio or tv remote)
            enableObstacleAvoidance();
            break;
             
    case 2: // cliff avoidance enabled (the robot does not move untill commands are 
	    // received from the radio or tv remote)
            enableCliffAvoidance();
            break;
    
    case 3: // both obstacle and cliff avoidance enabled (the robot does not move untill commands are
            // received from the radio or tv remote)
            enableObstacleAvoidance();
            enableCliffAvoidance();
            break;
            
    case 4: // random colors on RGB leds; small green leds turned on
            GREEN_LED0_ON;
            GREEN_LED1_ON;
            GREEN_LED2_ON;
            GREEN_LED3_ON;
            GREEN_LED4_ON;
            GREEN_LED5_ON;
            GREEN_LED6_ON;
            GREEN_LED7_ON;
            updateRedLed(pwm_red);
            updateGreenLed(pwm_green);
            updateBlueLed(pwm_blue);
            break;
             
    case 5: // random colors on RGB leds; obstacle avoidance enabled; robot start moving automatically
            // (motors speed setting)
            updateRedLed(pwm_red);
            updateGreenLed(pwm_green);
            updateBlueLed(pwm_blue);
            enableObstacleAvoidance();
            setLeftSpeed(25);
            setRightSpeed(25);
            break;
            
    case 6: // WiSARD train selector
            wisard_train (&w, arrayWisard, int tagClasse);
            
    case 7: // WiSARD Classify selector
            wisard_classify (&w, arrayWisard);
  }

  if(currentSelector != 0) {
    handleMotorsWithSpeedController();  
  }

  if(prevSelector != currentSelector) {	// in case the selector is changed, reset the robot state
    disableObstacleAvoidance();
    disableCliffAvoidance();
    GREEN_LED0_OFF;
    GREEN_LED1_OFF;
    GREEN_LED2_OFF;
    GREEN_LED3_OFF;
    GREEN_LED4_OFF;
    GREEN_LED5_OFF;
    GREEN_LED6_OFF;
    GREEN_LED7_OFF;
    pwm_red = 255;
    pwm_green = 255;
    pwm_blue = 255;
    updateRedLed(pwm_red);
    updateGreenLed(pwm_green);
    updateBlueLed(pwm_blue);
  }
  prevSelector = currentSelector;

}



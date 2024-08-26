#include <stdio.h>
#include <stdlib.h>
#include <esp32/rom/ets_sys.h>
#include <esp_task_wdt.h>
#include "driver/gpio.h"
#include "pins.h"
#include "single_linked_list.h"
#include "travel.h"

#define LED_PIN_LEVEL_TOP 21
#define LED_PIN_LEVEL_MID 18
#define LED_PIN_LEVEL_BOT 19
#define BUTTON_PIN 12

#define PUSH_TIME_US 250000 // 250 ms

// Used to not allow button pushes that are too close to each other in time
static volatile uint64_t lastPush = -PUSH_TIME_US;

//Just a counter keeping track of which travel need is next to process.
static volatile int travel_need_counter = 0;

// This data structure holds information about 
static volatile travel_need travel_needs[50];

static struct singleLinkedList *singleList;

void blinkLED(int LEDToBlink){
  gpio_set_level(LEDToBlink, 0);
  vTaskDelay(60);
  gpio_set_level(LEDToBlink, 1);
  vTaskDelay(60);
}

// This function is called when button is pushed
static void handle_push(void *arg) {
    
    // Disable interrupts
    ESP_ERROR_CHECK(gpio_intr_disable(BUTTON_PIN));

    // Get the current time 
    uint64_t now = esp_timer_get_time();

    // If enough time passed, we should consider this event as a genuine push
    if ((now - lastPush) > PUSH_TIME_US) {
      lastPush = now;
      
        //Get next travel need from list and do something with it
        travel_need current_travel_need = travel_needs[travel_need_counter];
        addElementSingleLinkedList(singleList, current_travel_need);


        /*
        //Now we are just blinking the LEDs. You need to update this code.
        uint32_t level = travel_need_counter % 4;

        if (level == 0) {
            gpio_set_level(LED_PIN_LEVEL_UP, 1);
            gpio_set_level(LED_PIN_LEVEL_MID, 0);
            gpio_set_level(LED_PIN_LEVEL_BOT, 0); 
        } 

        else if (level == 1 || level == 3) {
            gpio_set_level(LED_PIN_LEVEL_UP, 0);
            gpio_set_level(LED_PIN_LEVEL_MID, 1);
            gpio_set_level(LED_PIN_LEVEL_BOT, 0);
        }
        
        else {
            gpio_set_level(LED_PIN_LEVEL_UP, 0);
            gpio_set_level(LED_PIN_LEVEL_MID, 0);
            gpio_set_level(LED_PIN_LEVEL_BOT, 1); 
        }
        */

        //Increase travel need counter
        travel_need_counter++;
    }
    // Re-enable interrupts
    ESP_ERROR_CHECK(gpio_intr_enable(BUTTON_PIN));
}

void app_main() {

    //Initialize travel needs (50 randomly generated travel needs)
    travel_needs[0].origin = 2; travel_needs[0].destination = 1;
    travel_needs[1].origin = 1; travel_needs[1].destination = 2;
    travel_needs[2].origin = 1; travel_needs[2].destination = 2;
    travel_needs[3].origin = 0; travel_needs[3].destination = 2;
    travel_needs[4].origin = 0; travel_needs[4].destination = 2;
    travel_needs[5].origin = 2; travel_needs[5].destination = 1;
    travel_needs[6].origin = 1; travel_needs[6].destination = 2;
    travel_needs[7].origin = 1; travel_needs[7].destination = 0;
    travel_needs[8].origin = 0; travel_needs[8].destination = 1;
    travel_needs[9].origin = 1; travel_needs[9].destination = 0;
    travel_needs[10].origin = 1; travel_needs[10].destination = 2;
    travel_needs[11].origin = 0; travel_needs[11].destination = 1;
    travel_needs[12].origin = 0; travel_needs[12].destination = 2;
    travel_needs[13].origin = 0; travel_needs[13].destination = 1;
    travel_needs[14].origin = 0; travel_needs[14].destination = 2;
    travel_needs[15].origin = 0; travel_needs[15].destination = 1;
    travel_needs[16].origin = 2; travel_needs[16].destination = 1;
    travel_needs[17].origin = 2; travel_needs[17].destination = 1;
    travel_needs[18].origin = 1; travel_needs[18].destination = 0;
    travel_needs[19].origin = 2; travel_needs[19].destination = 1;
    travel_needs[20].origin = 1; travel_needs[20].destination = 0;
    travel_needs[21].origin = 0; travel_needs[21].destination = 1;
    travel_needs[22].origin = 1; travel_needs[22].destination = 2;
    travel_needs[23].origin = 0; travel_needs[23].destination = 2;
    travel_needs[24].origin = 2; travel_needs[24].destination = 1;
    travel_needs[25].origin = 1; travel_needs[25].destination = 0;
    travel_needs[26].origin = 1; travel_needs[26].destination = 2;
    travel_needs[27].origin = 0; travel_needs[27].destination = 2;
    travel_needs[28].origin = 1; travel_needs[28].destination = 0;
    travel_needs[29].origin = 1; travel_needs[29].destination = 2;
    travel_needs[30].origin = 0; travel_needs[30].destination = 1;
    travel_needs[31].origin = 1; travel_needs[31].destination = 2;
    travel_needs[32].origin = 0; travel_needs[32].destination = 2;
    travel_needs[33].origin = 0; travel_needs[33].destination = 2;
    travel_needs[34].origin = 1; travel_needs[34].destination = 2;
    travel_needs[35].origin = 2; travel_needs[35].destination = 1;
    travel_needs[36].origin = 0; travel_needs[36].destination = 2;
    travel_needs[37].origin = 1; travel_needs[37].destination = 0;
    travel_needs[38].origin = 0; travel_needs[38].destination = 2;
    travel_needs[39].origin = 2; travel_needs[39].destination = 1;
    travel_needs[40].origin = 0; travel_needs[40].destination = 1;
    travel_needs[41].origin = 0; travel_needs[41].destination = 1;
    travel_needs[42].origin = 0; travel_needs[42].destination = 1;
    travel_needs[43].origin = 1; travel_needs[43].destination = 0;
    travel_needs[44].origin = 0; travel_needs[44].destination = 2;
    travel_needs[45].origin = 2; travel_needs[45].destination = 1;
    travel_needs[46].origin = 2; travel_needs[46].destination = 1;
    travel_needs[47].origin = 2; travel_needs[47].destination = 1;
    travel_needs[48].origin = 0; travel_needs[48].destination = 2;
    travel_needs[49].origin = 1; travel_needs[49].destination = 0;

    initLEDPin(LED_PIN_LEVEL_TOP);
    initLEDPin(LED_PIN_LEVEL_MID);
    initLEDPin(LED_PIN_LEVEL_BOT);
    initButtonPin(BUTTON_PIN);
    
    singleList = malloc(sizeof(struct singleLinkedList));
    initSingleLinkedList(singleList);


    ESP_ERROR_CHECK(gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_NEGEDGE));

    // Activate the interrupts for the GPIOs
    ESP_ERROR_CHECK(gpio_install_isr_service(0));

    // Add a handler to the ISR for pin BUTTON_PIN
    ESP_ERROR_CHECK(gpio_isr_handler_add(BUTTON_PIN, handle_push, (void*) BUTTON_PIN));

    int current_position = 0;
    int next_position = 0;
    int goTo = 0;
    int alreadyBeenToOriginFlag = 0;

    int state_top = 2;
    int state_mid = 1;
    int state_bot = 0;
    

    // This is where you most likely put your main elevator code. 
    while(1) {
      if(singleList->first != NULL){
        int origin = singleList->first->travel_need.origin;
        int destination = singleList->first->travel_need.destination;
    

        if (!alreadyBeenToOriginFlag){
          goTo = origin;
        }else if(alreadyBeenToOriginFlag){
          goTo = destination;
        }

        switch (current_position){
          case 0:
            printf("Level 0\n");
            blinkLED(LED_PIN_LEVEL_BOT);

            if ((goTo == state_mid) || (goTo == state_top)) {
              next_position = state_mid;
              printf("Passing Level 0\n");
              gpio_set_level(LED_PIN_LEVEL_BOT, 0);
            }else if(goTo == state_bot){
              next_position = state_bot;
              printf("Staying Level 0\n");
            }
            break;

          
          case 1:
            printf("Level 1\n");
            blinkLED(LED_PIN_LEVEL_MID);

            if (goTo == state_bot) {
              next_position = state_bot;
              printf("Passing Level 1\n");
              gpio_set_level(LED_PIN_LEVEL_MID, 0);
            }else if(goTo == state_top){
              next_position = state_top;
              printf("Passing Level 1\n");
              gpio_set_level(LED_PIN_LEVEL_MID, 0);
            }else if(goTo == state_mid){
              next_position = state_mid;
              printf("Staying Level 1\n");
            }
            break;

            
          case 2:
            printf("Level 2\n");
            blinkLED(LED_PIN_LEVEL_TOP);

            if ((goTo == state_bot) || (goTo == state_mid)) {
              next_position = state_mid;
              printf("Passing Level 2\n");
              gpio_set_level(LED_PIN_LEVEL_TOP, 0);
            }else if(goTo == state_top){
              next_position = state_top;
              printf("Staying Level 2\n");
            }
            break;


          default:
            break;
          }
        current_position = next_position;
        vTaskDelay(367);

        if (current_position == destination && alreadyBeenToOriginFlag){
          removeFirstElementSingleLinkedList(singleList);
          alreadyBeenToOriginFlag = 0;
          printf("Reached destination: %i \n", destination);

          if(destination == 0){
            blinkLED(LED_PIN_LEVEL_BOT);
          }else if(destination == 1){
            blinkLED(LED_PIN_LEVEL_MID);
          }else if (destination == 2){
            blinkLED(LED_PIN_LEVEL_TOP);
          }
          
        }else if(current_position == origin){
          alreadyBeenToOriginFlag = 1;
          printf("At origin %i \n", origin);
          
        }
    } else{
      vTaskDelay(1); // Feeds the dog
    }
  }
}
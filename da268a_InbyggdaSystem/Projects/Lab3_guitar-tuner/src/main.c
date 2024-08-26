#include <stdio.h>
#include <esp_task_wdt.h>
#include <driver/gpio.h>
#include "sampler.h"
#include "notes.h"
#include "pins.h"

#define LED1pin 12 // White/blue
#define LED2pin 13 // Red
#define BUTTON_PIN 18
#define ESP_INTR_FLAG_DEFAULT 0 
#define PUSH_TIME_US 250000 // 250 ms 


static volatile int counter = 0; 
static volatile uint64_t lastPush = -PUSH_TIME_US; 
static void buttonPress_handler(void *arg) { 
    gpio_intr_disable(BUTTON_PIN);
    
    uint64_t now = esp_timer_get_time(); 
    if ((now - lastPush) > PUSH_TIME_US) { 
      lastPush = now; 

      counter++;
      if(counter >= 6){
        counter = 0;
      }
      

    } 

    gpio_intr_enable(BUTTON_PIN);
}


void app_main() {
  // init timer, ADC, LEDs, and button pins
  initTimer();
  initADC();
  initLEDPin(LED1pin);
  initLEDPin(LED2pin);
  initButtonPin(BUTTON_PIN);
  
  // activate the interrupts for the GPIOs
  gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_NEGEDGE);
  gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);

  // add the ISR handler for the given pin
  gpio_isr_handler_add(BUTTON_PIN, buttonPress_handler, (void*) BUTTON_PIN);
  
  

  setLED(LED1pin, 1); 
  setLED(LED2pin, 0); 
  vTaskDelay(pdMS_TO_TICKS(500)); 
  setLED(LED1pin, 0); 
  setLED(LED2pin, 1); 
  vTaskDelay(pdMS_TO_TICKS(500)); 
  setLED(LED1pin, 1); 
  setLED(LED2pin, 1); 
  vTaskDelay(pdMS_TO_TICKS(1000));
  setLED(LED1pin, 0); 
  setLED(LED2pin, 0); 

  startSampling(6000);

  while(1){
    // Signal the user that it’s time to start
   

    // Sample sound for some time
    vTaskDelay(pdMS_TO_TICKS(1000));

    // Print the note on the serial line
    float fr = getFrequency();
    //printf("Frequency is %.2f\n", fr);
    char note[] = "1234";
    freq2note(fr, note, counter);
    printf("Note is %s\n", note);

    resetSampling();
  }
}





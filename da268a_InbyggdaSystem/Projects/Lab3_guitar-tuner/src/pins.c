#include "pins.h"
#include <stdio.h>
#include <driver/gpio.h>



void initLEDPin(uint8_t pinN){

    gpio_config_t configLED;
    configLED.pin_bit_mask = (u_int64_t)1 << pinN;
    configLED.mode = GPIO_MODE_OUTPUT;
    configLED.pull_down_en = 0; 
    configLED.pull_up_en = 0;

    gpio_config(&configLED);
}

void initButtonPin(uint8_t pinN){

    gpio_config_t configBTN;
    configBTN.pin_bit_mask = (u_int64_t)1 << pinN;
    configBTN.mode = GPIO_MODE_INPUT;
    configBTN.pull_down_en = 0; 
    configBTN.pull_up_en = 1;
    
    configBTN.intr_type = GPIO_PIN_INTR_NEGEDGE;
    gpio_config(&configBTN);
} 
  
void setLED(uint8_t pinN, uint8_t level){
    if (level) { 
        gpio_set_level(pinN, 1); 
    } 
    else { 
        gpio_set_level(pinN, 0);
    } 
} 


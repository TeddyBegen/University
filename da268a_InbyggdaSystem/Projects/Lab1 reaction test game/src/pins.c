#include "pins.h" 
#include "driver/gpio.h" 

#define LED_A 12
#define LED_B 14
#define BUTTON_A 27
#define BUTTON_B 26



/* initialises the 4 pins */ 
void initPins() 
{ 
    gpio_config_t configLED;
    configLED.pin_bit_mask = (u_int64_t)1 << LED_A;
    configLED.pin_bit_mask |= (u_int64_t)1 << LED_B;
    configLED.mode = GPIO_MODE_OUTPUT;
    configLED.pull_down_en = 0; 
    configLED.pull_up_en = 0;

    gpio_config(&configLED);

    gpio_config_t configBTN;
    configBTN.pin_bit_mask = (u_int64_t)1 << BUTTON_A;
    configBTN.pin_bit_mask |= (u_int64_t)1 << BUTTON_B;
    configBTN.mode = GPIO_MODE_INPUT;
    configBTN.pull_down_en = 0; 
    configBTN.pull_up_en = 1; 

    gpio_config(&configBTN);

    // init the 2 LEDs pins as output and the 2 buttons' pins as input 
    // you will need to use gpio_config() 
} 
 
/* switches LED A on if level!=0 or off if level==0*/ 
void setLEDA(uint8_t level) 
{ 
    if (level) 
    { 
        gpio_set_level(LED_A, 1); 
        // set the pin of LED A to ON 
        // you probably need to use gpio_set_level() 
    } 
    else 
    { 
        gpio_set_level(LED_A, 0);
        // set the pin of LED A to OFF 
    } 
} 
 
/* switches LED B on if level!=0 or off if level==0*/ 
void setLEDB(uint8_t level) 
{ 
    if (level){
        gpio_set_level(LED_B, 1); 
    }
    else{
        gpio_set_level(LED_B, 0);
    }
} 
 
/* tells if button A is currently being pressed */ 
uint8_t isButtonAPressed() 
{ 
    // read the value of button A 
    // if using a pull-up, the button is pressed when the pin is LOW
    int value = gpio_get_level(BUTTON_A);

    //return value; // return 1 if A is pressed, 0 otherwise 
    if(value == 1){
        return 0;
    }else{
        return 1;
    }
}

/* tells if button A is currently being pressed */ 
uint8_t isButtonBPressed() 
{ 
    int value = gpio_get_level(BUTTON_B);

    if(value == 1){
        return 0;
    }else{
        return 1;
    }
} 
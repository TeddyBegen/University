#include <math.h>
#include <string.h>
#include <stdio.h>
#include <esp_task_wdt.h>
#include <driver/gpio.h>
#include "notes.h"
#include "pins.h"

#define LED1pin 12 // White/blue
#define LED2pin 13 // Red

void rightTone(){
    setLED(LED1pin, 1);
    setLED(LED2pin, 1);
    vTaskDelay(pdMS_TO_TICKS(250));
    setLED(LED1pin, 0);
    setLED(LED2pin, 0);
}

void lowTone(){
    setLED(LED1pin, 1);
    vTaskDelay(pdMS_TO_TICKS(250));
    setLED(LED1pin, 0);
}

void highTone(){
    setLED(LED2pin, 1);
    vTaskDelay(pdMS_TO_TICKS(250));
    setLED(LED2pin, 0);
}

void freq2note(float freq, char *stringbuff, int counter){

    int n = round(12*log2(freq/440));

    if      ((n == 0) || (n == -12)){
        strcpy(stringbuff, "A");
    }else if((n == 1) || (n == -11)){
        strcpy(stringbuff, "A#");
    }else if((n == 2) || (n == -10)){
        strcpy(stringbuff, "B");
    }else if((n == 3) || (n == -9)){
        strcpy(stringbuff, "C");
    }else if((n == 4) || (n == -8)){
        strcpy(stringbuff, "C#");
    }else if((n == 5) || (n == -7)){
        strcpy(stringbuff, "D");
    }else if((n == 6) || (n == -6)){
        strcpy(stringbuff, "D#");
    }else if((n == 7) || (n == -5)){
        strcpy(stringbuff, "E");
    }else if((n == 8) || (n == -4)){
        strcpy(stringbuff, "F");
    }else if((n == 9 )|| (n == -3)){
        strcpy(stringbuff, "F#");
    }else if((n == 10) || (n == -2)){
        strcpy(stringbuff, "G");
    }else if((n == 11) || (n == -1)){
        strcpy(stringbuff, "G#");
    }

    if(counter == 0){
        int k = round(12*log2(freq/329.63));

        if( (-0.05 < k) && (k < 0.05) ){
            strcpy(stringbuff, "E4");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }

    }
    else if ( counter == 1 ) {
        int k = round(12*log2(freq/246.94));
        
        if( (-0.05 < n) && (n < 0.05) ){
            strcpy(stringbuff, "B3");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }
    }
    else if ( counter == 2 ) {
        int k = round(12*log2(freq/196.00));
        
        if( (-0.05 < n) && (n < 0.05) ){
            strcpy(stringbuff, "G3");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }
    }
    else if (counter == 3) {
        int k = round(12*log2(freq/146.83));
        
        if( (-0.05 < n) && (n < 0.05) ){
            strcpy(stringbuff, "D3");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }
    }
    else if (counter == 4) {
        int k = round(12*log2(freq/110.00));
        
        if( (-0.05 < n) && (n < 0.05) ){
            strcpy(stringbuff, "A2");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }
    }
    else if (counter == 5) {
        int k = round(12*log2(freq/82.41));
        
        if( (-0.05 < n) && (n < 0.05) ){
            strcpy(stringbuff, "E2");
            rightTone();
        }
        else if(-0.05 > k){
            lowTone();
        }
        else if(0.05 < k){
            highTone();
        }
    }
}
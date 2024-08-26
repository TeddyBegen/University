#include <driver/gpio.h>
#include <esp32/rom/ets_sys.h>
#include <esp_task_wdt.h> 
#include "pins.h" 
#include "random.h" 
 
/* 
  Waits for "millis" milliseconds without upsetting the watchdog timer 
*/ 
void waitMs(unsigned int millis) 
{ 
    TickType_t delay = millis / portTICK_PERIOD_MS; 
    vTaskDelay(delay); 
} 
 
void app_main() 
{ 
    initPins(); 
 
    while (1) 
    { 
        // signal that the game is about to start 
        // you can flash LEDs in a certain way for it
        setLEDA(1); 
        setLEDB(0); 
        waitMs(500); 
        setLEDA(0); 
        setLEDB(1); 
        waitMs(500); 
        setLEDB(1); 
        setLEDA(1); 
        waitMs(1000);
        // switch both LEDs off
        setLEDA(0);
        setLEDB(0);
 
        // get a random duration between 3 and 5 seconds 
        int r = getRandommsecs(3000, 5000);
        printf("%.6f", r);
        printf("%d", "HEJ");
        // wait that random duration 
        waitMs(r);
        // switch both LEDs ON 
        setLEDA(1);
        setLEDB(1);
 
        uint8_t winner = 0; 
        while (!winner) 
        { 
            // check if either button A or B are pressed 

            // if any is pressed, set winner to 1 for A or 2 for B 
        if (isButtonAPressed()) 
        { 
            winner = 1;
        } 
        else if (isButtonBPressed()) 
        { 
            winner = 2;
        } 
        } 
 
        // if A wins, flash LED A and switch off B 
        // if B wins, flash LED B and switch off A 
        if(winner == 1){
            setLEDA(1); 
            setLEDB(0);
            waitMs(300); 
            setLEDA(0);
            waitMs(300);
            setLEDA(1); 
            waitMs(300); 
            setLEDA(0);
            waitMs(300);
            setLEDA(1); 
            waitMs(300); 
        }else if(winner == 2){
            setLEDB(1); 
            setLEDA(0);
            waitMs(300); 
            setLEDB(0);
            waitMs(300);
            setLEDB(1); 
            waitMs(300); 
            setLEDB(0);
            waitMs(300);
            setLEDB(1); 
            waitMs(300);             
        }
 
        // switch off both A and B and wait for some time to restart the game 
        setLEDA(0);
        setLEDB(0);
        waitMs(2000);
    } 
} 
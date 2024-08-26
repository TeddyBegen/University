#include "sampler.h"
#include <stdio.h>
#include <driver/gpio.h>
#include <driver/adc.h>
#include <soc/adc_channel.h> 
#include <esp_timer.h>

esp_timer_create_args_t timer_args;
esp_timer_handle_t timer;

int lastValue = 0;
int currentValue = 0;
int nbrOfCrossings = 0;
int samples = 0;
float samplingRate = 0;

int startTime = 0;
int endTime = 0;


int mathNbrOfCrossings = 0;
int mathEndTime = 0;
int mathStartTime = 0;


void sampler(void* arg){
    int val = adc1_get_raw(ADC1_GPIO32_CHANNEL);
    
    lastValue = currentValue;
    currentValue = val;
    if(lastValue < 1250 && currentValue > 1250){
        nbrOfCrossings++;
    }
    else if(lastValue > 1250 && currentValue < 1250){
        nbrOfCrossings++;
    }

    //getFrequency(val);
}


void initTimer(){
  esp_err_t esp_timer_init(void);
  
  timer_args.callback = &sampler;

  esp_timer_create(&timer_args, &timer);

}

void initADC(){
    // ADC1 supports GPIOs 32 - 39, let's choose 32 where we have our fantastic 10kHz range microphone. 
    // GPIOs - ADC channels mapping is done with macros ADC1_GPION_CHANNEL, so in our case ADC1_GPIO32_CHANNEL 
 
    // start ADC 
    adc_power_acquire(); 
 
    // configure pin 
    //adc_gpio_init(ADC_UNIT_1, ADC1_GPIO32_CHANNEL); 
 
    // use full 12 bits width 
    adc1_config_width(ADC_WIDTH_BIT_12); 
 
    // set attenuation to support full scale voltage 
    adc1_config_channel_atten(ADC1_GPIO32_CHANNEL, ADC_ATTEN_DB_11); 
 
    // let's setup a pull-up on that pin 
    // this must be called after initialisation of the ADC or it will be ignored 
    //gpio_pullup_en(32); 
}

void startSampling(int freq){
    //samplingRate = (float) freq;
    esp_timer_start_periodic(timer, (1000000/freq) );
    startTime = (int) esp_timer_get_time();
}

void stopSampling(){
    endTime = (int) esp_timer_get_time();
    esp_timer_stop(timer);
    
    mathNbrOfCrossings = nbrOfCrossings;
    mathStartTime = startTime;
    mathEndTime = endTime;
    nbrOfCrossings = 0;
}

float getFrequency(){
    /**
    float freq = 0;
    
    lastValue = currentValue;
    currentValue = val;
    
    
    if(lastValue < 1250 && currentValue > 1250){
        nbrOfCrossings++;
    }

    if(lastValue > 1250 && currentValue < 1250){
        nbrOfCrossings++;
    }
    
    samples++;

    if(samples == 500){
        freq = nbrOfCrossings/(2*(500/samplingRate));
        samples = 0;
        nbrOfCrossings = 0;
        printf("Frequency is %.2f\n", freq);
    }
    **/
        
    float time = ((float) (mathEndTime-mathStartTime))/1000000;    
    return ( mathNbrOfCrossings/(2*time));
}

void resetSampling(){
    mathNbrOfCrossings = nbrOfCrossings;
    mathEndTime = (int) esp_timer_get_time();
    mathStartTime = startTime;

    nbrOfCrossings = 0;
    startTime = (int) esp_timer_get_time();
}
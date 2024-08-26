#include "random.h"
#include <stdio.h>

/* Returns a random number contained between min and max. 
   min: minimum number of ms 
   max: maximum number of ms 
*/ 
int getRandommsecs(int min, int max){
    uint32_t random = (uint32_t) esp_random();
    float randomf = (float) random/UINT32_MAX;
    float math = (float) min + randomf * (max-min);
    return math;

}
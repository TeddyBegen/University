#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"
static volatile int notFull = 1;


void initCircularBuffer(struct circularBuffer* bufferPtr, int* data, int maxLength) {
  bufferPtr->data = data;
  bufferPtr->head = 0;
  bufferPtr->tail = 0;
  bufferPtr->maxLength = maxLength;
  bufferPtr->nbrOfElements = 0;
}

int contains(struct circularBuffer* bufferPtr, int value) {
    for (size_t i = 0; i < bufferPtr->maxLength; i++) {
        if(bufferPtr->data[i] == value) {
            return value;
        }
    }
    return INT_MIN;
}

int addElement(struct circularBuffer* bufferPtr, int value) {
    
    if(notFull == 1){
            //här ska else fan va om det skiter sig
        if(bufferPtr->nbrOfElements == 0){      
            bufferPtr->data[bufferPtr->tail] = value;
            bufferPtr->nbrOfElements++;
            //printf("\n om nbr of elements == 0 \n");
            return value;
        }else if(bufferPtr->nbrOfElements != 0){
            if(bufferPtr->data[bufferPtr->tail] == INT_MIN){
                bufferPtr->data[bufferPtr->tail] = value;
                bufferPtr->nbrOfElements++;
                //printf("\nAdd to empty tail\n");
                if(bufferPtr->nbrOfElements == bufferPtr->maxLength){
                    bufferPtr->tail = bufferPtr->head;
                    //printf("\nArray is full\n");
                    notFull = 0;
                    return INT_MIN;
                }
                else{
                    notFull = 1;
                    return value;
                }   
            }else{
                if(bufferPtr->tail+1 >= bufferPtr->maxLength){
                    bufferPtr->tail = 0;
                    //printf("\n om tail pekar på sista element i arrayen börja om från början\n");
                }else{
                    bufferPtr->tail++;
                    //printf("\nöka tail\n");
                }
                bufferPtr->data[bufferPtr->tail] = value;
                bufferPtr->nbrOfElements++;

                if(bufferPtr->nbrOfElements >= bufferPtr->maxLength){
                    bufferPtr->tail = bufferPtr->head;
                    notFull = 0;
                }else{
                    notFull = 1;
                }
                
                return value;
            }
        }else{
            return INT_MIN;
        }
    }else{
        printf("\nArray is full\n");
        return INT_MIN;
        //printf("\n \n");
    }
    
    
     /*if(bufferPtr->nbrOfElements == bufferPtr->maxLength){
        //printf("\nArray is full\n");
        bufferPtr->tail = bufferPtr->head;
        return INT_MIN;
        */
    
}

int removeValue(struct circularBuffer* bufferPtr, int value) {
    
    int tempArray[bufferPtr->maxLength];
    // Removes all instances of value in buffer, and saves how many were removed
    int foundValue = 0;
    if (bufferPtr->nbrOfElements != 0){
        
        for (size_t i = 0; i < bufferPtr->maxLength; i++){
            if(bufferPtr->data[i] == value){
                foundValue = 1; 
                bufferPtr->data[i] = INT_MIN;
                //printf("\nRemove %d\n", value);
                bufferPtr->nbrOfElements--;
                notFull = 1;
            }
        }

        /*while (i != bufferPtr->tail) {
            if(bufferPtr->data[i] == value){
                foundValue = 1; 
                bufferPtr->data[i] = INT_MIN;
                bufferPtr->nbrOfElements--;
                notFull = 1;
            }

            i++;
            if(i > bufferPtr->maxLength){
                i = 0;
            }
        }*/

    }else{
        return INT_MIN;
    }
    
    // Copies the current buffer to the temp array and empties buffer
    for (size_t j = 0; j < bufferPtr->maxLength; j++) {
        tempArray[j] = bufferPtr->data[j];
        bufferPtr->data[j] = INT_MIN;
    }
    // Copies the temp array to the new buffer, and removing all empty spaces between values
    int tempArrayCount = bufferPtr->head;
    int dataCount = bufferPtr->head;
    int copiedData = 0;
    while (copiedData != bufferPtr->nbrOfElements){
            //Checks if value from temp array is "0"
        if(tempArray[tempArrayCount] != INT_MIN){
            bufferPtr->data[dataCount] = tempArray[tempArrayCount];
            dataCount++;
            copiedData++;
             
            if (dataCount > bufferPtr->maxLength) {
                dataCount = 0;
            }
        }
        tempArrayCount++;
        if (tempArrayCount > bufferPtr->maxLength){
            tempArrayCount = 0;
        }
    }
    // Sets the Tail pointer's new value in buffer, if it needs to loop around
    bufferPtr->tail = dataCount-1;

    if(foundValue == 1){
        return value;
    }else{
        return INT_MIN;
    }
}
int removeHead(struct circularBuffer* bufferPtr){
    //printf("\nRemove head\n");
    int value;
    if(bufferPtr->nbrOfElements == 0){
        return INT_MIN;
    }else{
        value = bufferPtr->data[bufferPtr->head];
        bufferPtr->data[bufferPtr->head] = INT_MIN;
        bufferPtr->nbrOfElements--;
        notFull = 1;

        if(bufferPtr->nbrOfElements != 0){
            bufferPtr->head++;
            //printf("\nIncrease Head\n");
        }else{
            bufferPtr->head = 0;
            //printf("\nSetting Head to 0\n");
        }

        /*
        if(bufferPtr->head+1 == bufferPtr->maxLength){
            bufferPtr->head = 0;
            //printf("\nSetting Head to 0\n");
        }else if(bufferPtr->nbrOfElements != 0){
            bufferPtr->head++;
            //printf("\nIncrease Head\n");
        }else{
            bufferPtr->head = 0;
        }
        */
        return value;
    }
}

void printBuffer(struct circularBuffer* bufferPtr){
    printf("\nHead pointer: %d\n", bufferPtr->head);
    printf("Tail pointer: %d\n", bufferPtr->tail);

    int i = 0;
    while (i != bufferPtr->maxLength){
        printf("%i\n", bufferPtr->data[i]);
        i++;
        if (i > bufferPtr->maxLength){
            i = 0;
        }
    }
}
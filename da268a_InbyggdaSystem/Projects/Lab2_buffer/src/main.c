#include <stdio.h>
#include <stdlib.h>
#include <esp32/rom/ets_sys.h>
#include "circular_buffer.h"

/*
 * Change the value of BUFFER_SIZE if you want to change the size of the buffer. 
 */ 
#define BUFFER_SIZE 4

void blackBoxTest1(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nHead removed: %d\n", removeHead(&buffer));
}

void blackBoxTest2(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nAdded element: %d\n", addElement(&buffer, 2));
    printf("\nHead removed: %d\n", removeHead(&buffer));
    printf("\nHead removed: %d\n", removeHead(&buffer));
}

void blackBoxTest3(struct circularBuffer buffer){
    for (size_t i = 0; i < BUFFER_SIZE; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
    }
    
    for (size_t i = 0; i < BUFFER_SIZE; i++){
        printf("\nHead removed: %d\n", removeHead(&buffer));
    }
}

void blackBoxTest4(struct circularBuffer buffer){
    for (size_t i = 0; i < BUFFER_SIZE+1; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
    }
}

void blackBoxTest5(struct circularBuffer buffer){
    for (size_t i = 0; i < BUFFER_SIZE+1; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
        printf("\nHead removed: %d\n", removeHead(&buffer));
    }
}

void blackBoxTest6(struct circularBuffer buffer){
    printf("\nContains: %d\n", contains(&buffer, 1));
}

void blackBoxTest7(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 3));
    printf("\nContains: %d\n", contains(&buffer, 3));
}

void blackBoxTest8(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 3));
    printf("\nAdded element: %d\n", addElement(&buffer, 4));
    printf("\nContains: %d\n", contains(&buffer, 4));
}

void blackBoxTest9(struct circularBuffer buffer){
    int value = 0;
    for (size_t i = 0; i < BUFFER_SIZE; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
        value = i;
    }
    printf("\nContains: %d\n", contains(&buffer, value));
}

void whiteBoxInitTest1(struct circularBuffer buffer){
    if(buffer.maxLength == BUFFER_SIZE){
        printf("\nbuffer.maxLength equals BUFFER_SIZE\n");
    }

    if(buffer.head == 0){
        printf("\nBuffer head equals 0\n");
    }
    if(buffer.tail == 0){
        printf("\nBuffer tail equals 0\n");
    }
}

void whiteBoxAddTest1(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printBuffer(&buffer);
}

void whiteBoxAddTest2(struct circularBuffer buffer){
    buffer.head++;
    buffer.tail++;
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printBuffer(&buffer);
}

void whiteBoxAddTest3(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nAdded element: %d\n", addElement(&buffer, 2));
    printBuffer(&buffer);
}

void whiteBoxAddTest4(struct circularBuffer buffer){
    for (size_t i = 0; i < BUFFER_SIZE-1; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
    }
    printf("\nAdded element: %d\n", addElement(&buffer, 10));
    printBuffer(&buffer);
}

void whiteBoxRemoveTest1(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nRemove value: %d\n", removeValue(&buffer, 1));
    printBuffer(&buffer);
}

void whiteBoxRemoveTest2(struct circularBuffer buffer){
    for (size_t i = 0; i < BUFFER_SIZE; i++){
        printf("\nAdded element: %d\n", addElement(&buffer, i));
    }
    printf("\nRemove value: %d\n", removeValue(&buffer, 0));
    printBuffer(&buffer);
}

void whiteBoxRemoveTest3(struct circularBuffer buffer){
    printf("\nRemove value: %d\n", removeValue(&buffer, 2));
    printBuffer(&buffer);
}

void whiteBoxHeadTest1(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nHead removed: %d\n", removeHead(&buffer));
    printBuffer(&buffer);
}

void whiteBoxHeadTest2(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nAdded element: %d\n", addElement(&buffer, 2));
    printf("\nHead removed: %d\n", removeHead(&buffer));
    printBuffer(&buffer);
}

void whiteBoxHeadTest3(struct circularBuffer buffer){
    printf("\nAdded element: %d\n", addElement(&buffer, 1));
    printf("\nAdded element: %d\n", addElement(&buffer, 2));
    printf("\nAdded element: %d\n", addElement(&buffer, 3));
    printf("\nHead removed: %d\n", removeHead(&buffer));
    printBuffer(&buffer);
}

void whiteBoxHeadTest4(struct circularBuffer buffer){
    printf("\nHead removed: %d\n", removeHead(&buffer));
    printBuffer(&buffer);
}



void app_main() {

    // Some code to help you get started
    struct circularBuffer buffer;
    int *buffer_data = (int*) malloc(BUFFER_SIZE * sizeof(int));
    initCircularBuffer(&buffer, buffer_data, BUFFER_SIZE);

    printf("\n\n\n");
    printf("Best buffer code ever!\n");
    ets_delay_us(1000000ul);

    blackBoxTest4(buffer);

    free(buffer_data);
}


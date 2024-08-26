#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"
#include "double_linked_list.h"


// Single linked list tests
void singleBlackBoxTest1(struct singleLinkedList* list){
    printf("Added element: %d\n", addElementSingleLinkedList(list, 1));
    printf("Added element: %d\n", addElementSingleLinkedList(list, 2));
    printSingleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementSingleLinkedList(list));
    printf("First element removed: %d\n", removeFirstElementSingleLinkedList(list));    
    printSingleLinkedList(list);
}

void singleBlackBoxTest2(struct singleLinkedList* list){
    printf("Element added: %d\n", addElementSingleLinkedList(list, 32));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 20));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 2));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 100));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 40));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 140));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 15));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 99));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 60));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 2110));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 45));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 67));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 89));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 20));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 2));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 9));
    printSingleLinkedList(list);
}

void singleWhiteBoxTest1(struct singleLinkedList* list){
    printf("Element added: %d\n", addElementSingleLinkedList(list, 1));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 6));
    printSingleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementSingleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printSingleLinkedList(list);
}

void singleWhiteBoxTest2(struct singleLinkedList* list){
    printf("Element added: %d\n", addElementSingleLinkedList(list, 32));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 20));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 2));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 99));
    printSingleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementSingleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printSingleLinkedList(list);
}

void singleWhiteBoxTest3(struct singleLinkedList* list){
    printf("Element added: %d\n", addElementSingleLinkedList(list, 32));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 20));
    printf("Element added: %d\n", addElementSingleLinkedList(list, 25));
    printSingleLinkedList(list);
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementSingleLinkedList(list));
    printSingleLinkedList(list);
}

// Double linked list tests
void doubleBlackBoxTest1(struct doubleLinkedList* list){
    printf("Added element: %d\n", addElementDoubleLinkedList(list, 1));
    printf("Added element: %d\n", addElementDoubleLinkedList(list, 2));
    printDoubleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementDoubleLinkedList(list));
    printf("First element removed: %d\n", removeFirstElementDoubleLinkedList(list));    
    printDoubleLinkedList(list);
}

void doubleBlackBoxTest2(struct doubleLinkedList* list){
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 32));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 20));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 2));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 100));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 40));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 140));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 15));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 99));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 60));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 2110));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 45));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 67));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 89));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 20));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 2));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 9));
    printDoubleLinkedList(list);
    
    
}

void doubleWhiteBoxTest1(struct doubleLinkedList* list){
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 1));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 6));
    printDoubleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementDoubleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printDoubleLinkedList(list);
}

void doubleWhiteBoxTest2(struct doubleLinkedList* list){
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 3));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 2));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 21));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 99));
    printDoubleLinkedList(list);
    printf("First element removed: %d\n", removeFirstElementDoubleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printDoubleLinkedList(list);
}

void doubleWhiteBoxTest3(struct doubleLinkedList* list){
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 32));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 20));
    printf("Element added: %d\n", addElementDoubleLinkedList(list, 25));
    printDoubleLinkedList(list);
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printf("Last element removed: %d\n", removeLastElementDoubleLinkedList(list));
    printDoubleLinkedList(list);
}

void app_main() {
    struct singleLinkedList *singleList = malloc(sizeof(struct singleLinkedList));
    struct doubleLinkedList *doubleList = malloc(sizeof(struct doubleLinkedList));
    initSingleLinkedList(singleList);
    initDoubleLinkedList(doubleList);

    // Add 2 elements, remove first twice
    //singleBlackBoxTest1(singleList);

    // Add a large amount of elements
    //singleBlackBoxTest2(singleList);

    // Add 2 elements, try to remove 3 elements
    singleWhiteBoxTest1(singleList);

    // Add 4 elements, remove first & last
    //singleWhiteBoxTest2(singleList);

    // Add 3 elements, remove last thrice
    //singleWhiteBoxTest3(singleList);

    // All are same as above, but using the doubly linked list
    //doubleBlackBoxTest1(doubleList);
    //doubleBlackBoxTest2(doubleList);
    //doubleWhiteBoxTest1(doubleList);
    //doubleWhiteBoxTest2(doubleList);
    //doubleWhiteBoxTest3(doubleList);
}
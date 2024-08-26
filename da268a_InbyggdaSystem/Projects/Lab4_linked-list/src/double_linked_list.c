#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"double_linked_list.h"


void printDoubleLinkedList(struct doubleLinkedList* list){
  if(list->first != NULL ){
    int counter = 0;
    struct doubleLinkedListElement *pointer = list->first;
    printf("\nElement %i: %d\n", counter, pointer->data);
    counter++;
    while(pointer->next != NULL){ // Traverse the linked list until next element != NULL
      pointer = pointer->next;
      printf("Element %i: %d\n", counter, pointer->data);
      counter++;
    }
  }else{
  printf("List is empty\n");
  }
}

int addElementDoubleLinkedList(struct doubleLinkedList* list, int value){
  struct doubleLinkedListElement *element, *pointer;
  element = malloc(sizeof(struct doubleLinkedListElement));  
  
  element->data = value;
  element->next = NULL;
  element->previous = NULL; // new


  if(list->first == NULL){
    list->first = element;
    list->last = element;
    return value;
  }else{
    list->last->next = element;
    element->previous = list->last;
    list->last = element;
  }


  int swapped;
  struct doubleLinkedListElement *ptr;
  struct doubleLinkedListElement*lastptr = NULL; 
  
  do{ 
    swapped = 0;
    ptr = list->first;
      //bubblesort
    while (ptr->next != lastptr) { 
      if (ptr->data > ptr->next->data) { 

        int temp = ptr->data; 
        ptr->data = ptr->next->data; 
        ptr->next->data = temp;
        swapped = 1; 
      } 
    ptr = ptr->next; // Increment to continue traversing the list
    } 
    lastptr = ptr; 
  } 
  while (swapped);
  return value;
} 


void initDoubleLinkedList(struct doubleLinkedList* list) {
  list->first = NULL;
  list->last = NULL;
}


int removeFirstElementDoubleLinkedList(struct doubleLinkedList* list){
  if (list->first == NULL){
    return INT_MIN;
 }else{
    int returnValue = list->first->data;                       // Save removed value to return later
    struct doubleLinkedListElement *temp = list->first->next; // Create a temp pointer to new first value
    free(list->first);                                       // Free allocated memory for old first
    list->first = temp;                                     // Set temp value to first
  return returnValue;
 }
} 


int removeLastElementDoubleLinkedList(struct doubleLinkedList* list) {
  if(list->first != NULL && list->first->next != NULL){
    struct doubleLinkedListElement *temp = list->last->previous;
    int returnValue = list->last->data; 
    free(list->last);
    list->last = temp;
    list->last->next = NULL;

    return returnValue;
  }else if(list->first != NULL && list->first->next == NULL){
    int returnValue = list->first->data;
    free(list->first);
    list->first = NULL;
    return returnValue;
  }else{
    return INT_MIN;
  }
}







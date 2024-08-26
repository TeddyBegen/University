#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"single_linked_list.h"


void printSingleLinkedList(struct singleLinkedList* list){
  if(list->first != NULL ){
    int counter = 0;
    struct singleLinkedListElement *pointer = list->first;
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


int addElementSingleLinkedList(struct singleLinkedList* list, int value){
  struct singleLinkedListElement *element, *pointer;
  element = malloc(sizeof(struct singleLinkedListElement));
  
  element->data = value;
  element->next = NULL;


  if(list->first == NULL){
    list->first = element;
    return value;
  }else{
    pointer = list->first;
    
    while(pointer->next != NULL){ // Traverse the linked list until next element != NULL
      pointer = pointer->next;
    }
    pointer->next = element;
  }


  int swapped;
  struct singleLinkedListElement *ptr;
  struct singleLinkedListElement *lastptr = NULL; 
  
  do{ 
    swapped = 0;
    ptr = list->first;
      //bubblesort
    while (ptr->next != lastptr) { 
      if (ptr->data < ptr->next->data) { 
        int temp = ptr->data; 
        ptr->data = ptr->next->data; 
        ptr->next->data = temp;

        swapped = 1; 
      } 
    ptr = ptr->next; 
    } 
    lastptr = ptr; 
  } 
  while (swapped);
  return value;
} 

void initSingleLinkedList(struct singleLinkedList* list) {
  list->first = NULL;
}

int removeFirstElementSingleLinkedList(struct singleLinkedList* list){
 if (list->first == NULL){
  return INT_MIN;
 }else{
  int returnValue = list->first->data;                       // Save removed value to return later
  struct singleLinkedListElement *temp = list->first->next; // Create a temp pointer to new first value
  free(list->first);                                       // Free allocated memory for old first
  list->first = temp;                                     // Set temp value to first
  return returnValue;
 }
} 


int removeLastElementSingleLinkedList(struct singleLinkedList* list){
  if(list->first != NULL && list->first->next != NULL){
  struct singleLinkedListElement *pointer = list->first;
    while(pointer->next != NULL){ // Traverse the linked list until next element != NULL
      if (pointer->next->next == NULL){

        int returnValue = pointer->next->data; 
        free(pointer->next);
        pointer->next = NULL;
        
        return returnValue;
      }else{
        pointer = pointer->next;
      }
    }
  }else if(list->first != NULL && list->first->next == NULL){
    int returnValue = list->first->data;
    free(list->first);
    list->first = NULL;
    return returnValue;
    }else{
      return INT_MIN;
    }
} 

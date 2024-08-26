#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "single_linked_list.h"

  volatile int counter = 0;
int nbrOfElements(){
  return counter;
}

void addElementSingleLinkedList(struct singleLinkedList* list, travel_need travel_need){
  struct singleLinkedListElement *element, *pointer;
  element = malloc(sizeof(struct singleLinkedListElement));
  
  element->travel_need = travel_need;
  element->next = NULL;


  if(list->first == NULL){
    list->first = element;
    counter++;
  }else{
    pointer = list->first;
    
    while(pointer->next != NULL){ // Traverse the linked list until next element != NULL
      pointer = pointer->next;
    }
    pointer->next = element;
    counter++;
  }

} 

void initSingleLinkedList(struct singleLinkedList* list) {
  list->first = NULL;
}

void removeFirstElementSingleLinkedList(struct singleLinkedList* list){
 if (list->first != NULL){                    
  struct singleLinkedListElement *temp = list->first->next; // Create a temp pointer to new first value
  free(list->first);                                       // Free allocated memory for old first
  list->first = temp;                                     // Set new first
  counter--;
 }
}

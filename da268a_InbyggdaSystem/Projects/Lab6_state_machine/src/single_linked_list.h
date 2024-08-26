#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "travel.h"

struct singleLinkedListElement{
  travel_need travel_need;
  struct singleLinkedListElement *next;
};

struct singleLinkedList{
  struct singleLinkedListElement *first;
};

int nbrOfElements();

void addElementSingleLinkedList(struct singleLinkedList* list, travel_need travel_need);

void initSingleLinkedList(struct singleLinkedList* list);

void removeFirstElementSingleLinkedList(struct singleLinkedList* list);

#endif

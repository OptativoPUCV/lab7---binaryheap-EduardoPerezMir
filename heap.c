#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    for (int i = 0; i < pq->capac; i++)
        if (pq->heapArray[i]->data == NULL)
        {
            pq->heapArray[i].data = data;
            pq->heapArray[i].priority = priority;
            break;
        }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* newHeap = NULL;
    newHeap = (Heap*) malloc(sizeof(Heap));
    if (newHeap == NULL) return NULL;
    newHeap->capac = 3;
    newHeap->size = 0;
    newHeap->heapArray = (heapElem*) malloc(sizeof(heapElem));
    if (newHeap->heapArray == NULL) return NULL;
    for (int i = 0; i < 3; i++)
    {
        newHeap->heapArray[i].data = NULL;
        newHeap->heapArray[i].priority = 0;
    }
    return newHeap;
}

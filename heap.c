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
    if (pq->capac == 0 || pq->size == 0)
        return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    int auxIndice = -1;
    int priorityAux;
    
    pq->size++;
    
    pq->heapArray[pq->size - 1].priority = priority;
    
    auxIndice = pq->size - 1;
    int j = auxIndice - 1;
    
    while (j >= 0)
    {
        if (pq->heapArray[auxIndice].priority >= pq->heapArray[j].priority)
        {
            priorityAux = pq->heapArray[auxIndice].priority;
            pq->heapArray[auxIndice].priority = pq->heapArray[j].priority;
            pq->heapArray[j].priority = priorityAux;
            auxIndice = j;
        }
        else
        {
            break;
        }
        j--;
    }
    pq->heapArray[auxIndice].data = data;
    printf("%d", auxIndice);
    
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* newHeap = NULL;
    newHeap = (Heap*) malloc(sizeof(Heap));
    if (newHeap == NULL) return NULL;
    newHeap->capac = 3;
    newHeap->size = 0;
    newHeap->heapArray = (heapElem*) malloc(sizeof(heapElem) * newHeap->capac);
    if (newHeap->heapArray == NULL) return NULL;
    for (int i = 0; i < newHeap->capac; i++)
    {
        newHeap->heapArray[i].data = NULL;
        newHeap->heapArray[i].priority = 0;
    }
    return newHeap;
}

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
    heapElem elemAux;
    
    for (int i = 0; i < pq->capac; i++)
    {
        if (pq->heapArray[i].data == NULL)
        {
            pq->heapArray[i].data = data;
            pq->heapArray[i].priority = priority;
            auxIndice = i;
            break;
        }
    }
    for (int i = auxIndice - 1; i >= 0; i--)
    {
        if (pq->heapArray[auxIndice].priority > pq->heapArray[i].priority)
        {
            elemAux = pq->heapArray[auxIndice];
            pq->heapArray[auxIndice] = pq->heapArray[i];
            pq->heapArray[i] = elemAux;
        }
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
    newHeap->heapArray = (heapElem*) malloc(sizeof(heapElem) * newHeap->capac);
    if (newHeap->heapArray == NULL) return NULL;
    for (int i = 0; i < newHeap->capac; i++)
    {
        newHeap->heapArray[i].data = NULL;
        newHeap->heapArray[i].priority = 0;
    }
    return newHeap;
}

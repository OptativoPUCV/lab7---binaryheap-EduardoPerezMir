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
    int indexAux = pq->size;
    pq->size++;
    
    printf("%d", 1/2);
        if (priority > pq->heapArray[(indexAux - 1) / 2].priority )
        {
            pq->heapArray[indexAux] = pq->heapArray[(indexAux - 1) / 2];
            indexAux = (indexAux - 1) / 2;
        }

    
    pq->heapArray[indexAux].data = data;
    pq->heapArray[indexAux].priority = priority;
    printf("%d", indexAux);
    
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

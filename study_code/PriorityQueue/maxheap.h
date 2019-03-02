#ifndef __MAX_HEAP_H__
#define __MAX_HEAP_H__

#define TRUE    1
#define FALSE   0

typedef int HData;
typedef HData PriorityComp(HData d1, HData d2);

typedef struct _heap
{
    PriorityComp *get_prior;
    int num_of_data;
    int heap_size;
    HData *heapArr;
} Heap;

typedef void VisitFuncPtr(HData data);

void HeapInit(Heap * pheap, int heap_size, PriorityComp pc);
int HIsEmpty(Heap * pheap);

void HInsert(Heap *pheap, HData data);
HData HDeleteMax(Heap *pheap);

void HPrintAll(Heap *pheap);

#endif

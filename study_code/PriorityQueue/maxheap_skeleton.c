#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "maxheap.h"

// 1
void HeapInit(Heap * pheap, int heap_size, PriorityComp pc)
{
    pheap->get_prior = pc;
    pheap->heap_size = heap_size;
    pheap->heapArr = malloc(sizeof(HData) * (heap_size + 1));
    pheap->num_of_data = 0;
}

// 2
int HIsEmpty(Heap * pheap)
{
    if (pheap->num_of_data == 0) return TRUE;
    return FALSE;
}

// 3
int GetParentIndex(int index)
{
    return index / 2;
}

int GetLChildIndex(int index)
{
    return index * 2;
}

int GetRChildIndex(int index)
{
    return index * 2 + 1;
}

int GetHiPriChildIndex(Heap *pheap, int index)
{
    if (GetLChildIndex(index) > pheap->num_of_data) {
        return FALSE;
    }else if (GetLChildIndex(index) == pheap->num_of_data) {
        return GetLChildIndex(index);
    }else {
        if (pheap->get_prior(pheap->heapArr[GetLChildIndex(index)], pheap->heapArr[GetRChildIndex(index)]) == pheap->heapArr[GetLChildIndex(index)]) {
            return GetLChildIndex(index);
        }
        return GetRChildIndex(index);
    }
}

void HInsert(Heap *pheap, HData data)
{
    if (pheap->num_of_data == pheap->heap_size) {
        printf("Max Heap is Full\n");
        return;
    }
    
    int target_idx = pheap->num_of_data + 1;
    while((pheap->get_prior(pheap->heapArr[GetParentIndex(target_idx)], data) == data) && GetParentIndex(target_idx)) {
        pheap->heapArr[target_idx] = pheap->heapArr[GetParentIndex(target_idx)];
        target_idx = GetParentIndex(target_idx);
    }
    pheap->heapArr[target_idx] = data;
    (pheap->num_of_data)++;
}

HData HDeleteMax(Heap *pheap)
{
    if (pheap->num_of_data == 0) {
        printf("Delete: Max Heap is empty.\n");
        return 0;
    }
    
    HData ret = pheap->heapArr[1];
    
    HData last_data = pheap->heapArr[pheap->num_of_data];
    int target_idx = 1;
    while(GetHiPriChildIndex(pheap, target_idx)) {
        int HiPriChildIndex = GetHiPriChildIndex(pheap, target_idx);
        HData child_data = pheap->heapArr[HiPriChildIndex];
        if (pheap->get_prior(last_data, child_data) == child_data) {
            pheap->heapArr[target_idx] = child_data;
            target_idx = HiPriChildIndex;
            continue;
        }
        break;
    }
    
    pheap->heapArr[target_idx] = last_data;
    (pheap->num_of_data)--;
    
    return ret;
}

double Log2(double n)
{
    return log(n) / log(2);
}

void HPrintAll(Heap *pheap)
{
    if (pheap->num_of_data == 0) {
        printf("Print: Max Heap is empty.\n");
        return;
    }

    printf("----------heap----------\n");
    int height = (int)Log2(pheap->num_of_data);
    int max_leaf_num = pow(2, height);
    for(int i = 1; i <= pheap->num_of_data; i++) {
        int cur_depth = (int)Log2(i);
        int next_depth = (int)Log2(i+1);
        int wing_size = pow(2, height - cur_depth) - 1;
        for (int j = 0; j < wing_size; j++) {
            printf("   ");
        }
        if (pheap->heapArr[i] < 10) printf(" %d ", pheap->heapArr[i]);
        else if (pheap->heapArr[i] > 10 ) printf("%3d", pheap->heapArr[i]);
        for (int j = 0; j < wing_size; j++) {
            printf("   ");
        }
        printf("   ");
        if (cur_depth != next_depth) {
            printf("\n");
        }
    }
    printf("\n");
}

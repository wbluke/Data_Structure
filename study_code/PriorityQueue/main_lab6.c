#include <stdio.h>
#include "maxheap.h"

#define MAX_BUFFER_SIZE 10

int GetPrior(int d1, int d2)
{
    if (d1 > d2) return d1;
    else return d2;
}

void ExecuteHeapOp(Heap *pheap, char *buffer)
{
    char command = buffer[0];
    int heap_size;
    int data;

    switch (command){
        case 'n':
            sscanf(buffer, "%c %d", &command, &heap_size);
            HeapInit(pheap, heap_size, GetPrior);
            break;
        case 'i':
            sscanf(buffer, "%c %d", &command, &data);
            HInsert(pheap, data);
            break;
        case 'd':
            HDeleteMax(pheap);
            break;
        case 'p':
            HPrintAll(pheap);
            break;
    }
}

int main(int argc, char const *argv[])
{
    Heap heap;
    char buffer[MAX_BUFFER_SIZE];
 
    // FILE *fp = fopen(argv[1],"r");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        
        ExecuteHeapOp(&heap, buffer);
    }
    // fclose(fp);

    return 0;
}

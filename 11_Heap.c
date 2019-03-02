/* 11_Heap.c */
/*
 Priority Queue 를 구현하기 좋은 Heap.
 특정한 조건을 가지는 트리를 Heap이라 한다.
 완전 이진 트리이면서, 부모 노드가 자식 노드에 저장된 값보다 크거나 같은 트리를 Heap이라 한다.
 데이터를 저장할 때는 완전 이진 트리를 만족하는 마지막 노드에 추가할 데이터를 놓은 후, 순차적으로 부모 노드와 비교해나가면서 자리를 찾아나간다.
 데이터를 삭제할 때는 루트 노드를 반환시키고, 자식 노드 중 큰 값을 가지는 노드를 비교하여 자리를 찾아 Heap을 유지시킨다.
 인덱스의 접근 편의성 때문에, 연결리스트보다는 배열로 구현하는 것이 유리하다.
 Priority Queue의 구현을 위해 각 노드의 우선순위 비교가 필요한데, Heap에 유연성을 주기 위해 사용자가 Comp함수를 지정하도록 한다.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef char HData;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);


// 함수 구현 ================================
void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
	//	if(ph->heapArr[GetLChildIDX(idx)].pr 
	//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}


// main =================================
int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
//	return ch1-ch2;
}

int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}


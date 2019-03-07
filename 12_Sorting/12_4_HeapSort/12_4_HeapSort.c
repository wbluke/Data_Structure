/*
 HeapSort : Heap의 루트 노드에 저장된 값이 가장 크다는 Heap의 특성을 이용하여 정렬하는 방법.
 비교함수를 정렬하고자 하는 우선순위에 맞게 구성하여 Heap을 만든 후, 
 모든 정렬 대상을 힙에 다 넣었다가 하나씩 꺼내면서 배열에 넣으면 정렬이 된다. 
 Heap의 데이터 저장과 삭제 모두 시간 복잡도가 O(log_2(n)) 이고, 정렬대상의 수를 n이라 하면 
 HeapSort의 시간 복잡도는 O(nlog_2(n))임을 알 수 있다. 
 앞선 O(n^2)의 단순 정렬들에 비해서 꽤나 효율적인 알고리즘임을 알 수 있다. 
 */

#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2-n1;
//	return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// 정렬 대상을 가지고 힙을 구성한다.
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성한다. 
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}

int main(void)
{
	int arr[4] = {3, 4, 2, 1};
	int i;

	HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

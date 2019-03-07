/*
 InsertionSort : 배열을 정렬된 앞 쪽 부분과 정렬되지 않은 뒤 쪽 부분으로 나눠서
 현재 정렬할 데이터를 정렬된 부분의 특정 위치에 '삽입'하는 정렬 방법이다.
 삽입할 위치를 발견하고 데이터를 한 칸씩 뒤로 밀 수도 있지만, 데이터를 한 칸씩 뒤로 밀면서 삽입할 위치를 찾는다. 
 삽입 정렬은 정렬대상의 대부분이 이미 정렬되어 있는 경우 매우 빠르게 동작한다. 
 하지만 최악의 경우 BubbleSort나 SelectionSort와 마찬가지로 이중 반복문을 돌아야하므로 시간복잡도는 O(n^2)이다. 
 */

#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
			else
				break;   // 삽입 위치 찾은 후 탈출
		}

		arr[j+1] = insData;  // 찾은 위치에 정렬 대상 삽입
	}
}


int main(void)
{
	int arr[5] = {5, 3, 2, 4, 1};
	int i;

	InserSort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
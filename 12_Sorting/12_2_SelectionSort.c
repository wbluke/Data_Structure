/*
 SelectionSort : 각 경우마다 최솟값을 찾아서 가장 왼쪽으로 이동시킨다.
 원래 그 자리에 있던 데이터는 빈 자리에 가져다 놓는다. 
 결과적으로는 교환이지만 원론적으로는 빈 공간을 하나 생성해놓고 한개씩 정렬 방식에 맞게 채우는 방식이다.
 비교 연산의 시간복잡도는 O(n^2)이고, 대입 연산의 시간복잡도는 최악의 경우와 최선의 경우 모두 O(n)이다. 
 BubbleSort와 SelectionSort의 우열을 가리는 것은 사실상 무의미하다. 
 */

#include <stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		maxIdx = i;    

		for(j=i+1; j<n; j++)   // 최솟값 탐색
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* 교환 */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}


int main(void)
{
	int arr[4] = {3, 4, 2, 1};
	int i;

	SelSort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
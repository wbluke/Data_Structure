/*
 BubbleSort : 정렬의 우선순위가 가장 낮은, 제일 큰 값을 맨 뒤로 보내기.
 항상 인덱스 0 부터 비교를 시작하며, 맨 끝 인덱스부터 정렬을 완료해나가는 경우기 때문에 길이를 하나씩 줄이면 된다. 
 시간복잡도는 O(n^2)으로 성능면에서는 부담스러운 방법이다. 
*/

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


int main(void)
{
	int arr[4] = {3, 2, 4, 1};
	int i;

	BubbleSort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
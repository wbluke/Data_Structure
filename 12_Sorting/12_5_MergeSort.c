/*
 MergeSort : divide and conquer 알고리즘에 의한 정렬 방법이다. 
 하나의 원소로 쪼개질 때까지 재귀호출로 분할한 다음, 정렬하면서 병합하는 과정을 거친다.
 정렬하면서 병합하는 MergeTwoArea() 함수는 먼저 정렬한 배열을 담을 sortArr를 생성해놓고,
 mid를 기준으로 두 배열을 한 원소씩 비교해나가면서 sortArr를 채워간다. 
 while문의 조건이 fIdx<=mid && rIdx<=right 인 것은 그 때문이다. 
 while문이 끝난 후에는 한 쪽 배열의 삽입이 끝나고 다른 쪽 배열이 남아있다는 뜻이므로, 
 어디가 원소가 남은 배열인지 확인해서 남은 배열들을 다 넣어주면 된다. 

 정렬의 대상인 데이터의 수가 n개일 때, 각 병합의 단계마다 최대 n번의 비교연산이 진행된다. 
 병합 과정은 log_2(n)이므로 병합 정렬의 비교연산에 대한 시간복잡도는 O(nlog_2(n))이다. 
 데이터가 이동하는 경우는 데이터 병합 때 한 번, 임시 배열을 원래 배열로 옮길 때 한 번이다.
 따라서 이동연산의 시간복잡도는 마찬가지로 O(nlog_2(n))이다. 
 */

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right)
	{
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid)
	{
		for(i=rIdx; i<=right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
		// 중간 지점 계산
        mid = (left+right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int i;

	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
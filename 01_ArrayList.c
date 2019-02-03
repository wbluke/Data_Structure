/* 01_ArrayList.c */

#include <stdio.h>

#define TRUE    1
#define FALSE    0

#define LIST_LEN    100
typedef int LData;

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

// ArrayList 초기화
void ListInit(List * plist)
{
    (plist->numOfData) = 0;
    (plist->curPosition) = -1;
}

// 데이터 저장
void LInsert(List * plist, LData data)
{
    if(plist->numOfData > LIST_LEN)
    {
        puts("저장이 불가능합니다.");
        return;
    }
    
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

// curPosition 재설정으로 데이터의 참조가 맨 앞에서부터 진행되도록
int LFirst(List * plist, LData * pdata)
{
    if(plist->numOfData == 0)
        return FALSE;
    
    (plist->curPosition) = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

// curPosition을 증가시켜서 순서대로 데이터를 참조
int LNext(List * plist, LData * pdata)
{
    if(plist->curPosition >= (plist->numOfData)-1)
        return FALSE;
    
    (plist->curPosition)++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

// 최근에 참조된 데이터 삭제
LData LRemove(List * plist)
{
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos];
    
    for(i=rpos; i<num-1; i++)
        plist->arr[i] = plist->arr[i+1];
    
    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}

// 데이터의 개수
int LCount(List * plist)
{
    return plist->numOfData;
}


int main(void)
{
    // ArrayList의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    
    // 5개의 데이터 저장
    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 22);  LInsert(&list, 22);
    LInsert(&list, 33);
    
    //저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    
    // 숫자 22 탐색하여 모두 삭제
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    // 삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}

/*
현재 데이터의 수 : 5
11 11 22 22 33

현재 데이터의 수 : 3
11 11 33 
*/

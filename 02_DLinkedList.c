#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE    0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
} Node;

typedef struct _linkedList
{
    Node * head;
    Node * cur;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

// 함수 구현 ==================================
void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL; // 사용자가 정의한 정렬 함수
    plist->numOfData = 0;
}

// 사용자 정렬 함수 comp가 존재하지 않을 때 : head에 새 노드 추가
void FInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    
    (plist->numOfData)++;
}

// 사용자 정렬 함수 comp가 존재할 때
void SInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    Node * pred = plist->head; // pred는 더미 노드를 가리킴
    newNode->data = data;
    
    // 현재 노드가 마지막 노드가 아니면서, 아직 data가 들어갈 자리를 찾지 못했을 때
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next;
    }
    
    newNode->next = pred->next;
    pred->next = newNode;
    
    (plist->numOfData)++;
}

// 사용자 정의 정렬 함수가 존재하지 않으면 FInsert, 존재하면 SInsert
void LInsert(List * plist, LData data)
{
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
    if(plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

// 삭제 후의 cur 포인터를 앞으로 이동시키기 위해 before의 도움을 받는다. 
LData LRemove(List * plist)
{
    Node * rpos = plist->cur;
    LData rdata = rpos->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List * plist)
{
    return plist->numOfData;
}

// 함수 포인터. 사용자 정의 정렬 함수 comp를 세팅.
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}

/*
 위에 구현한 리스트에서 정렬함수의 조건은
 두 개의 인자를 전달받아, 첫 번째 인자의 정렬 우선순위가 높으면 0, 낮으면 1을 반환하는 것이다.
*/
// 임의로 정한 간단한 정렬함수
int WhoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0;   // 만약 내림차순으로 구현을 원하면 0과 1을 뒤바꾸면 된다.
    else
        return 1;
}

int main(void)
{
    List list;
    int data;
    ListInit(&list);
    
    SetSortRule(&list, WhoIsPrecede); // 정렬의 기준 등록
    
    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 22);  LInsert(&list, 22);
    LInsert(&list, 33);
    
    // 데이터 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    
    // 데이터가 22인 노드 삭제
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
    
    // 삭제 후 데이터 출력
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

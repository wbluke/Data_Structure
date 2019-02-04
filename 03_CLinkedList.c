/* 03_CLInkedList.c */
/*
 원형 연결 리스트(Circular LinkedList)
 모든 노드가 단방향으로 연결되어 있다.
 데이터를 머리에 추가하는 것과 꼬리에 추가하는 것을 tail 노드 하나로 처리한다.
    꼬리 : tail
    머리 : tail->next
 LNext함수는 무한히 호출 가능하다.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE    0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _CLL
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
} CList;

typedef CList List;


// 함수 구현 ==================================
void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// 머리에 노드를 추가
void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    
    (plist->numOfData)++;
}

// 꼬리에 노드를 추가
void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode; // 유일하게 차이가 나는 부분 : tail을 newNode로 옮기기
    }
    
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->tail == NULL)    // 저장된 노드가 없다면
        return FALSE;
    
    plist->before = plist->tail; // before가 꼬리를 가리키게 한다.
    plist->cur = plist->tail->next; // cur이 머리를 가리키게 한다.
    
    *pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 반환
    return TRUE;
}

int LNext(List * plist, Data * pdata)
{
    if(plist->tail == NULL)    // 저장된 노드가 없다면
        return FALSE;
    
    plist->before = plist->cur; // before가 다음 노드를 가리키게 한다.
    plist->cur = plist->cur->next; // cur이 다음 노드를 가리키게 한다.
    
    *pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 반환
    return TRUE;
}

Data LRemove(List * plist)
{
    Node * rpos = plist->cur;
    Data rdata = rpos->data;
    
    if(rpos == plist->tail) // 예외 1 : 삭제 대상을 tail이 가리킨다면
    {
        if(plist->tail == plist->tail->next) // 예외 2 : 그리고 마지막 남은 노드라면
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }
    
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

// main ===========================================
int main(void)
{
    // 원형 연결 리스트의 생성 및 초기화
    List list;
    int data, i, nodeNum;
    ListInit(&list);
    
    // 리스트에 5개의 데이터를 저장
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
    
    // 리스트에 저장된 데이터를 연속 3회 출력
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        for(i=0; i<LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");
    
    // 2의 배수를 찾아서 모두 삭제
    nodeNum = LCount(&list);
    
    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
            LRemove(&list);
        
        for(i=0; i < nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
                LRemove(&list);
        }
    }
    
    // 전체 데이터 1회 출력
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    return 0;
}

/*
 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
 1 3 5
 */

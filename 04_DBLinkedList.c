/* 04_DBLInkedList.c */
/*
 양방향 연결 리스트, 이중 연결 리스트 (Doubly LinkedList)
 하나의 노드가 자신의 왼쪽과 오른쪽 노드를 동시에 가리키는 구조.
 아래 소스는 더미 노드는 없는 상태. 필요하다면 양쪽에 더미 노드를 추가해서 구현 가능. (DBDLinkedList)
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
    struct _node * prev;
} Node;

typedef struct _dbLinkedList
{
    Node * head;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;


// 함수 구현 ================================
void ListInit(List * plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->head; // 새 노드가 기존 노드를 가리키도록
    if(plist->head != NULL)
        plist->head->prev = newNode; // 두 번째 이후의 노드를 추가할 때만 실행
                                     // 기존 노드가 새 노드를 가리키도록
    newNode->prev = NULL; // 새 노드의 prev에 NULL 저장
    plist->head = newNode; // head가 새 노드를 가리키게 한다.
    
    (plist->numOfData)++;
}

// 첫 번째 노드의 데이터 조회 : 양방향이기 때문에 before 가 존재하지 않는다.
int LFirst(List * plist, Data * pdata)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    
    return TRUE;
}

// 두 번째 이후 노드의 데이터 조회 : 양방향이기 때문에 before 가 존재하지 않는다.
int LNext(List * plist, Data * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

// LNext의 반대 방향으로 데이터 조회
int LPrevious(List * plist, Data * pdata)
{
    if(plist->cur->prev == NULL)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LCount(List * plist)
{
    return plist->numOfData;
}


// main ===================================
int main(void)
{
    // 양방향 연결 리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    
    // 8개의 데이터 저장
    LInsert(&list, 1);  LInsert(&list, 2);
    LInsert(&list, 3);  LInsert(&list, 4);
    LInsert(&list, 5);  LInsert(&list, 6);
    LInsert(&list, 7);  LInsert(&list, 8);
    
    // 저장된 데이터 조회
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        // 오른쪽 노드로 이동하며 데이터 조회
        while(LNext(&list, &data))
            printf("%d ", data);
        
        // 왼쪽 노드로 이동하며 데이터 조회
        while(LPrevious(&list, &data))
            printf("%d ", data);
        
        printf("\n\n");
    }
    
    return 0;
}

/*
 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8
 */

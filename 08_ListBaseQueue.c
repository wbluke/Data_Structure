/* 08_ListBaseQueue.c */
/*
 연결 리스트 기반 Queue
 큐가 빈 경우 : Front가 NULL이다.
 EnQueue는 첫 번째 노드와 두 번째 이후 노드의 과정이 차이가 있다. NULL인 Front를 조정해주어야 하기 때문.
 DeQueue는 Rear와 상관없이 Front만 조절해주면 된다. 큐의 비어있음은 Front에만 의존하기 때문이다.
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

typedef struct _lQueue
{
    Node * front;
    Node * rear;
} LQueue;

typedef LQueue Queue;

//함수 구현 =============================
void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;
    
    free(delNode);
    return retData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    return pq->front->data;
}

// main ===================================

int main(void)
{
    // Queue의 생성 및 초기화
    Queue q;
    QueueInit(&q);
    
    // 데이터 넣기
    Enqueue(&q, 1);  Enqueue(&q, 2);
    Enqueue(&q, 3);  Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    // 데이터 꺼내기
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));
    
    return 0;
}

/* 1 2 3 4 5 */

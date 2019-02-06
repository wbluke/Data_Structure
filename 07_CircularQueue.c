/* 07_CircularQueue.c */
/*
 배열 기반 Queue
 Front와 Rear로 FIFO를 구현한다. 데이터 입력은 Rear, 데이터 반환은 Front
 다만 데이터의 입력과 반환이 계속 이루어지는 상황에서, 앞쪽이 비어있는데 뒤쪽 인덱스까지 꽉 찬 경우,
 Rear를 앞으로 다시 보내준다. 다른 관점에서 본다면 두 포인터가 계속 돌아가는 원형 모양의 배열이라고도 볼 수 있다.
 
 문제는 두 포인터가 계속 돌아다니면서, 상대적으로 큐의 시작과 끝이 모호해졌다는 점이다.
 이 문제를 해결하기 위해, 처음부터 배열에서 공간 하나를 비우고 시작하도록 한다.
 즉, Front와 Rear가 같은 인덱스를 가리킬 때, 그 빈 공간을 제외한 부분을 큐로 사용하도록 한다.
 그리고 다음과 같이 EnQueue와 DeQueue의 연산을 정의하도록 한다.
 
 EnQueue : Rear가 가리키는 위치를 한 칸 이동시킨 다음에, Rear가 가리키는 위치에 데이터를 저장한다.
 DeQueue : Front가 가리키는 위치를 한 칸 이동시킨 다음에, Front가 가리키는 위치에 저장된 데이터를 반환 및 소멸한다.
 
 그리고 구현할 큐의 특성을 다음과 같이 정리한다.
 
 원형 큐가 텅 빈 상태 : Front와 Rear가 동일한 위치를 가리킨다.
 원형 큐가 꽉 찬 상태 : Rear가 가리키는 위치의 앞을 Front가 가리킨다.
 
 그리고 Front와 Rear의 회전을 돕기 위해, 큐의 다음 위치에 해당하는 인덱스 값을 반환하는 NextPosIdx()를 정의한다.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE    0

#define QUE_LEN    100
typedef int Data;

typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

// 함수 구현 ================================

void QueueInit(Queue * pq) // 텅 빈 경우 Front와 Rear는 동일 위치 가리킴
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear) // 큐가 텅 비었다면
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if(pos == QUE_LEN-1) // 배열의 마지막 요소의 인덱스 값이라면
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->front) // 큐가 꽉 찼다면
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    pq->rear = NextPosIdx(pq->rear); // Rear를 한 칸 이동
    pq->queArr[pq->rear] = data; // Rear가 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    pq->front = NextPosIdx(pq->front); // Front를 한 칸 이동
    return pq->queArr[pq->front]; // Front가 가리키는 데이터 반환
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    return pq->queArr[NextPosIdx(pq->front)];
}

// main =======================================

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

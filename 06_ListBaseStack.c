/* 06_StackBaseStack.c */
/*
 연결리스트 기반 Stack
 새로운 노드는 머리에 추가하는 형태
 head 포인터가 Top의 역할을 한다.
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

typedef struct _listStack
{
    Node * head;
} ListStack;

typedef ListStack Stack;

// 함수 구현 ===============================

void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pstack->head;
    
    pstack->head = newNode;
}

Data SPop(Stack * pstack) // head가 가리키는 노드를 소멸시키고, 그 노드의 데이터를 반환
{
    Data rdata;
    Node * rnode;
    
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rdata = pstack->head->data;
    rnode = pstack->head;
    
    pstack->head = pstack->head->next;
    free(rnode);
    
    return rdata;
}

Data SPeek(Stack * pstack) // 다음에 나올 노드가 무엇인지 보기만 하는 함수
{
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->head->data;
}

// main ====================================

int main(void)
{
    // Stack의 생성 및 초기화
    Stack stack;
    StackInit(&stack);
    
    // 데이터 넣기
    SPush(&stack, 1);  SPush(&stack, 2);
    SPush(&stack, 3);  SPush(&stack, 4);
    SPush(&stack, 5);
    
    // 데이터 꺼내기
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
    
    return 0;
}

/* 5 4 3 2 1 */

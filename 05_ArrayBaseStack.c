/* 05_ArrayBaseStack.c */
/*
 배열 기반 Stack
 인덱스 0의 배열 요소가 스택의 바닥이다.
 마지막 요소를 Top으로 표시한다. 요소가 없으면 Top은 -1
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE    0
#define STACK_LEN    100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

// 함수 구현 ====================================

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) // 다음에 나올 요소를 밖으로 꺼내고 반환하는 함수
{
    int rIdx;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack) // 다음에 나올 요소를 확인만 하는 함수
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->stackArr[pstack->topIndex];
}

// main ==========================================

int main(void)
{
    // Stack 생성 및 초기화
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

/*
 슬롯과 노드를 구분하는 방법에는 여러가지가 있는데, 
 여기서는 노드의 데이터 부분에 Slot의 주소값을 저장해 놓는 방법을 사용하였다. 
 */

#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include "Slot2.h"

#define TRUE	1
#define FALSE	0

// typedef int LData;
typedef Slot LData;

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

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif
/*
 직접 정의한 해쉬 함수를 등록하도록 디자인 되어있다. 
 Slot의 배열로 테이블을 구성하였다.
 */

#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h" 

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
	Slot tbl[MAX_TBL];
	HashFunc * hf;
}Table;


void TBLInit(Table * pt, HashFunc * f);

void TBLInsert(Table * pt, Key k, Value v);

Value TBLDelete(Table * pt, Key k);

Value TBLSearch(Table * pt, Key k);

#endif
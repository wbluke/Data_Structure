/*
 슬롯 : 데이터를 저장할 수 있는 각각의 공간
 SimpleHashTable에서와 달리 enum이 사용되지 않았는데 
 Chaining 충돌 해결법을 사용하면 굳이 슬롯의 상태를 저장해놓을 필요가 없기 때문이다. 
 같은 Key값이 충돌이 일어난다면 LinkedList 형태로 그 key값에 노드를 추가시켜주는 방법이다. 
 */

#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot
{
	Key key;
	Value val;
} Slot;

#endif
/*
 슬롯 : 데이터를 저장할 수 있는 각각의 공간
 슬롯의 상태를 나타내기 위해 enum을 사용했는데, EMTPY는 한번도 사용이 된 적이 없음을, 
 DELETED는 사용된 적이 있으나 지금 데이터가 없고, INUSE는 사용 중인 슬롯임을 의미한다. 
 EMPTY와 DELETED를 구분하는 이유는 충돌 문제를 해결하는 과정에서 필요하기 때문이다. 
 슬롯의 상태가 DELETED라면 충돌이 발생했음을 의심하여 선형 조사법, 이차 조사법 등을 추가로 진행시켜야 한다. 
 */

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;

#endif
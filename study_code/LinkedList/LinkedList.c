#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 1   -->   구현 순서
void InitList(List *plist)
{
    plist->head = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// 5
void LInsert(List *plist, ElementType new_element, ElementType key_element)
{
    Node * new = (Node *) malloc(sizeof(Node));
    new->element = new_element;
    new->next = NULL;
    
    if (key_element == -1) {
        new->next = plist->head;
        plist->head = new;
    }
    else if (FindNode(plist, key_element)) {
        new->next = plist->cur->next;
        plist->cur->next = new;
    }
    else {
        printf("Insertion(%d) Failed: element %d is not in the list.\n", new_element, key_element);
    }
}

// 6
void LDelete(List *plist, ElementType key_element)
{
    if(FindNode(plist, key_element)) {
        if(plist->cur->next == NULL) { // 원소가 1개일 경우
            free(plist->cur);
            plist->head = NULL;
            return;
        }
        plist->before->next = plist->cur->next;
        free(plist->cur);
        return;
    }
    printf("Deletion Failed: element %d is not in the list.\n", key_element);
}

void DeleteList(List *plist)
{
    if(plist->head == NULL) return;
    
    plist->cur = plist->head;
    if(plist->cur->next == NULL) { // 원소가 1개일 경우
        free(plist->cur);
        plist->head = NULL;
        return;
    }
    while(plist->cur != NULL) {
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
        free(plist->before);
    }
    plist->head = NULL;
}

// 3
void PrintList(List *plist)
{
    if (plist->head == NULL) {
        printf("List is Empty.\n");
    }
    
    plist->cur = plist->head;
    while(plist->cur != NULL) {
        printf("key:%d\t", plist->cur->element);
        plist->cur = plist->cur->next;
    }
    printf("\n");
}

// 4
int FindNode(List *plist, ElementType key_element)
{
    plist->cur = plist->head;
    while(plist->cur != NULL) {
        if (plist->cur->element == key_element) {
            return TRUE;
        }
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }
    return FALSE;
}

void FindPreviousNode(List *plist, ElementType key_element)
{
    if(FindNode(plist, key_element)) {
        if(plist->cur->element == plist->head->element) {
            printf("Key of the previous node of %d is header.\n", key_element);
            return;
        }
        printf("Key of the previous node of %d is %d.\n", key_element, plist->before->element);
        return;
    }
    printf("Could not find %d in the list.\n", key_element);
}

int LCount(List *plist)
{
    int count = 0;
    
    plist->cur = plist->head;
    while(plist->cur != NULL) {
        count++;
        plist->cur = plist->cur->next;
    }
    return count;
}

// 2
int IsEmpty(List *plist)
{
    if (plist->head == NULL) {
        return TRUE;
    }
    return FALSE;
}

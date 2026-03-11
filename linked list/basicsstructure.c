#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct{
    Node* head;   // dummy head
    int size;
}MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = malloc(sizeof(Node));  // dummy node
    obj->head->next = NULL;
    obj->size = 0;
    return obj;
}


int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    Node* cur = obj->head->next;

    for(int i=0;i<index;i++)
        cur = cur->next;

    return cur->val;
}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    Node* node = malloc(sizeof(Node));
    node->val = val;

    node->next = obj->head->next;
    obj->head->next = node;

    obj->size++;
}


void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    Node* cur = obj->head;

    while(cur->next != NULL)
        cur = cur->next;

    cur->next = node;

    obj->size++;
}


void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index > obj->size)
        return;

    if(index < 0)
        index = 0;

    Node* prev = obj->head;

    for(int i=0;i<index;i++)
        prev = prev->next;

    Node* node = malloc(sizeof(Node));
    node->val = val;

    node->next = prev->next;
    prev->next = node;

    obj->size++;
}


void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    if(index < 0 || index >= obj->size)
        return;

    Node* prev = obj->head;

    for(int i=0;i<index;i++)
        prev = prev->next;

    Node* del = prev->next;

    prev->next = del->next;

    free(del);

    obj->size--;
}


void myLinkedListFree(MyLinkedList* obj) {

    Node* cur = obj->head;

    while(cur != NULL){
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    free(obj);
}
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


typedef struct {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head =  (MyLinkedList*) malloc(sizeof( MyLinkedList));
    head->next = NULL;
    head->val = 0;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    while (index>0)
    {
        if(obj->next == NULL) break;
        obj = obj->next;
        index--;
    }
    if (index > 0) return -1;
    printf("point = %p", obj);
    return obj->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *buf = (MyLinkedList*) malloc(sizeof( MyLinkedList));
    buf->val = obj->val;
    buf->next = obj->next;
    obj->val = val;
    obj->next = buf;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    while (obj->next != NULL)
    {
        obj = obj->next;
    }
    MyLinkedList *buf = (MyLinkedList*) malloc(sizeof( MyLinkedList));
    buf->val = val;
    buf->next = NULL;
    obj->next = buf;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *buf = (MyLinkedList*) malloc(sizeof( MyLinkedList));
    MyLinkedList *buff = obj;
    if (index == 0) myLinkedListAddAtHead(obj, val);
    else {
        for (int i = 0; i < index-1; i++){
            obj = obj->next;
            if (obj == NULL) break;
        }
        if (obj != NULL && obj->next!=NULL){
            buf->next = obj->next;
            obj->next = buf;
            buf->val = val;
        }
        else if (obj != NULL && obj->next == NULL) myLinkedListAddAtTail(buff, val);
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    for (int i = 0; i < index-1; i++){
        obj = obj->next;
        if (obj == NULL) break;
    }
    if (obj != NULL && obj->next != NULL){
    printf("\ndel = %p\n", obj);
    MyLinkedList *buff = obj;
    printf("\nbuff before = %p\n", buff);
    buff = buff->next;
    printf("\nbuff after = %p\n", buff);
    obj->next = buff->next;
    }
    if (obj != NULL && obj->next == NULL){

    }
}

int main (){
    /*rer
    MyLinkedList *head = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    MyLinkedList *head1 = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    MyLinkedList *head2 = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    head->val = 1;
    head->next = head1;
    head1->val = 2;
    head1->next = head2;
    head2->val = 3;
    head2->next = NULL;
    myLinkedListAddAtTail(head, 5);
    myLinkedListAddAtHead(head, 6);
    myLinkedListAddAtIndex(head, 5, 44);
    */
    MyLinkedList* head = myLinkedListCreate();
    //int param_1 = myLinkedListGet(head, 0);
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtTail(head, 3);
    myLinkedListAddAtIndex(head, 3, 42);
    *((*head).next).next;
    //myLinkedListDeleteAtIndex(head, 0);
    //printf("%d ", myLinkedListGet(head, 1));              // return 2
    //myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
    //printf("%d ", myLinkedListGet(head, 1));              // return 3

    printf(" val = %d\n", myLinkedListGet(head, 0));
    printf(" val = %d\n", myLinkedListGet(head, 1));
    printf(" val = %d\n", myLinkedListGet(head, 2));
    printf(" val = %d\n", myLinkedListGet(head, 3));
    printf(" val = %d\n", myLinkedListGet(head, 4));
    printf(" val = %d\n", myLinkedListGet(head, 5));
    printf(" val = %d\n", myLinkedListGet(head, 6));

    return 0;
}

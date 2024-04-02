#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main (){
    return 0;
}
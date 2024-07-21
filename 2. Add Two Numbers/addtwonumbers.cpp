#include "addtwonumbers.h"
#include <__config>


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){

    ListNode* l = NULL;
    int carry = 0;
    while(l1 != NULL || l2 != NULL){
        int val1 = l1 == NULL ? 0 : l1->val;
        int val2 = l2 == NULL ? 0 : l2->val;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        l = addNode(l, sum % 10);
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry > 0){
        l = addNode(l, carry);
    }
    return l;
}


ListNode* Solution::addNode(ListNode* l, int val){
    if (l == NULL){
        l = new ListNode(val);
    }else{
        ListNode* p = l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = new ListNode(val);
    }
    return l;
}

void Solution::deleteNode(ListNode *l){

    ListNode* p = l;
    while(p != NULL){
        ListNode* q = p;
        p = p->next;
        delete q;
    }
}

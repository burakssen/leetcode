#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result = NULL;
    struct ListNode *tmp = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        if (result == NULL)
        {
            result = newNode;
            tmp = result;
        }
        else
        {
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    if (carry > 0)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        tmp->next = newNode;
    }
    return result;
}

void freeList(struct ListNode *l)
{
    struct ListNode *tmp;
    while (l != NULL)
    {
        tmp = l;
        l = l->next;
        free(tmp);
    }
}

struct ListNode *addNode(struct ListNode *l, int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    if (l == NULL)
    {
        l = newNode;
    }
    else
    {
        struct ListNode *tmp = l;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return l;
}
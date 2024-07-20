#include <stdio.h>
#include "addtwonumbers.h"

#include <unity.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1(void)
{
    int input1[] = {2, 4, 3};
    int input2[] = {5, 6, 4};
    int expected[] = {7, 0, 8};

    struct ListNode *l1 = NULL;
    for (int i = 0; i < 3; i++)
    {
        l1 = addNode(l1, input1[i]);
    }

    struct ListNode *l2 = NULL;
    for (int i = 0; i < 3; i++)
    {
        l2 = addNode(l2, input2[i]);
    }

    struct ListNode *result = addTwoNumbers(l1, l2);
    for (int i = 0; i < 3; i++)
    {
        TEST_ASSERT_EQUAL_INT(expected[i], result->val);
        result = result->next;
    }

    freeList(l1);
    freeList(l2);
    freeList(result);
}

void test_2(void)
{
    int input1[] = {0};
    int input2[] = {0};
    int expected[] = {0};

    struct ListNode *l1 = NULL;
    for (int i = 0; i < 1; i++)
    {
        l1 = addNode(l1, input1[i]);
    }

    struct ListNode *l2 = NULL;
    for (int i = 0; i < 1; i++)
    {
        l2 = addNode(l2, input2[i]);
    }

    struct ListNode *result = addTwoNumbers(l1, l2);
    for (int i = 0; i < 1; i++)
    {
        TEST_ASSERT_EQUAL_INT(expected[i], result->val);
        result = result->next;
    }

    freeList(l1);
    freeList(l2);
    freeList(result);
}

void test_3(void)
{
    int input1[] = {9, 9, 9, 9, 9, 9, 9};
    int input2[] = {9, 9, 9, 9};
    int expected[] = {8, 9, 9, 9, 0, 0, 0, 1};

    struct ListNode *l1 = NULL;
    for (int i = 0; i < 7; i++)
    {
        l1 = addNode(l1, input1[i]);
    }

    struct ListNode *l2 = NULL;
    for (int i = 0; i < 4; i++)
    {
        l2 = addNode(l2, input2[i]);
    }

    struct ListNode *result = addTwoNumbers(l1, l2);
    for (int i = 0; i < 8; i++)
    {
        TEST_ASSERT_EQUAL_INT(expected[i], result->val);
        result = result->next;
    }

    freeList(l1);
    freeList(l2);
    freeList(result);
}

int main(void)
{
    // Start Unity testing
    UNITY_BEGIN();
    // Run test functions
    RUN_TEST(test_1);
    RUN_TEST(test_2);
    RUN_TEST(test_3);
    return UNITY_END();
}
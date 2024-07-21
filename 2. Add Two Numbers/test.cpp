#include <cstdio>
#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>
#include "addtwonumbers.h"

TEST_CASE("Example 1")
{
    int input1[] = {2, 4, 3};
    int input2[] = {5, 6, 4};
    int output[] = {7, 0, 8};

    Solution s;
    ListNode *l1 = nullptr;
    l1 = s.addNode(l1, input1[0]);
    l1 = s.addNode(l1, input1[1]);
    l1 = s.addNode(l1, input1[2]);

    ListNode *l2 = nullptr;
    l2 = s.addNode(l2, input2[0]);
    l2 = s.addNode(l2, input2[1]);
    l2 = s.addNode(l2, input2[2]);

    ListNode *result = s.addTwoNumbers(l1, l2);

    for (int i = 0; i < 3; i++)
    {
        REQUIRE(result->val == output[i]);
        result = result->next;
    }

    s.deleteNode(l1);
    s.deleteNode(l2);
    s.deleteNode(result);
}

TEST_CASE("Example 2")
{
    int input1[] = {0};
    int input2[] = {0};
    int output[] = {0};

    Solution s;
    ListNode *l1 = nullptr;
    l1 = s.addNode(l1, input1[0]);

    ListNode *l2 = nullptr;
    l2 = s.addNode(l2, input2[0]);

    ListNode *result = s.addTwoNumbers(l1, l2);

    for (int i = 0; i < 1; i++)
    {
        REQUIRE(result->val == output[i]);
        result = result->next;
    }

    s.deleteNode(l1);
    s.deleteNode(l2);
    s.deleteNode(result);
}

TEST_CASE("Example 3")
{
    int input1[] = {9, 9, 9, 9, 9, 9, 9};
    int input2[] = {9, 9, 9, 9};
    int output[] = {8, 9, 9, 9, 0, 0, 0, 1};

    Solution s;
    ListNode *l1 = nullptr;
    l1 = s.addNode(l1, input1[0]);
    l1 = s.addNode(l1, input1[1]);
    l1 = s.addNode(l1, input1[2]);
    l1 = s.addNode(l1, input1[3]);
    l1 = s.addNode(l1, input1[4]);
    l1 = s.addNode(l1, input1[5]);
    l1 = s.addNode(l1, input1[6]);

    ListNode *l2 = nullptr;
    l2 = s.addNode(l2, input2[0]);
    l2 = s.addNode(l2, input2[1]);
    l2 = s.addNode(l2, input2[2]);
    l2 = s.addNode(l2, input2[3]);

    ListNode *result = s.addTwoNumbers(l1, l2);

    for (int i = 0; i < 8; i++)
    {
        REQUIRE(result->val == output[i]);
        result = result->next;
    }

    s.deleteNode(l1);
    s.deleteNode(l2);
    s.deleteNode(result);
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}

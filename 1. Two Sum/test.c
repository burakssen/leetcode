#include <stdio.h>

#include <unity.h>

#include "twosum.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1(void)
{
    // Example 1
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int *result1 = twoSum(nums1, 4, target1, &returnSize1);
    TEST_ASSERT_EQUAL_INT(0, result1[0]);
    TEST_ASSERT_EQUAL_INT(1, result1[1]);
    free(result1);
}

void test_2(void)
{
    // Example 2
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int *result2 = twoSum(nums2, 3, target2, &returnSize2);
    TEST_ASSERT_EQUAL_INT(1, result2[0]);
    TEST_ASSERT_EQUAL_INT(2, result2[1]);
    free(result2);
}

void test_3(void)
{
    // Example 3
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int *result3 = twoSum(nums3, 2, target3, &returnSize3);
    TEST_ASSERT_EQUAL_INT(0, result3[0]);
    TEST_ASSERT_EQUAL_INT(1, result3[1]);
    free(result3);
}

int main()
{
    // Start Unity testing
    UNITY_BEGIN();
    // Run test functions
    RUN_TEST(test_1);
    RUN_TEST(test_2);
    RUN_TEST(test_3);
    // End Unity testing
    return UNITY_END();
}
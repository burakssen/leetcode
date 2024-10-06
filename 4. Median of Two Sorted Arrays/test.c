#include <stdio.h>

#include "medianoftwosortedarrays.h"
#include <unity.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1(void)
{
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double result1 = findMedianSortedArrays(nums1, 2, nums2, 1);
    TEST_ASSERT_EQUAL_FLOAT(2.0, result1);
}

void test_2(void)
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    double result2 = findMedianSortedArrays(nums1, 2, nums2, 2);
    TEST_ASSERT_EQUAL_FLOAT(2.5, result2);
}

int main()
{
    // Start Unity testing
    UNITY_BEGIN();
    // Run test functions
    RUN_TEST(test_1);
    RUN_TEST(test_2);

    return UNITY_END();
}

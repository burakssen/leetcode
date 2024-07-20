#include <stdio.h>

#include "longestsubstringwithoutrepeatingcharacters.h"
#include <unity.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1(void)
{
    char *input1 = "abcabcbb";
    int result1 = lengthOfLongestSubstring(input1);
    TEST_ASSERT_EQUAL_INT(3, result1);
}

void test_2(void)
{
    char *input2 = "bbbbb";
    int result2 = lengthOfLongestSubstring(input2);
    TEST_ASSERT_EQUAL_INT(1, result2);
}

void test_3(void)
{
    char *input3 = "pwwkew";
    int result3 = lengthOfLongestSubstring(input3);
    TEST_ASSERT_EQUAL_INT(3, result3);
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

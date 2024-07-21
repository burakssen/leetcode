#include <catch2/catch_all.hpp>
#include "longestsubstring.h"

TEST_CASE("Test 1")
{
    Solution solution;
    std::string s = "abcabcbb";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 3);
}

TEST_CASE("Test 2")
{
    Solution solution;
    std::string s = "bbbbb";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 1);
}

TEST_CASE("Test 3")
{
    Solution solution;
    std::string s = "pwwkew";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 3);
}

TEST_CASE("Test 4")
{
    Solution solution;
    std::string s = "";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 0);
}

TEST_CASE("Test 5")
{
    Solution solution;
    std::string s = " ";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 1);
}

TEST_CASE("Test 6")
{
    Solution solution;
    std::string s = "au";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 2);
}

TEST_CASE("Test 7")
{
    Solution solution;
    std::string s = "dvdf";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 3);
}

TEST_CASE("Test 8")
{
    Solution solution;
    std::string s = "abba";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 2);
}

TEST_CASE("Test 9")
{
    Solution solution;
    std::string s = "aab";
    REQUIRE(solution.lengthOfLongestSubstring(s) == 2);
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
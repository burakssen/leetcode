#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>
#include "twosum.h"

TEST_CASE("Example 1")
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    std::vector<int> expected = {0, 1};
    REQUIRE(solution.twoSum(nums, target) == expected);
}

TEST_CASE("Example 2")
{
    std::vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution solution;
    std::vector<int> expected = {1, 2};
    REQUIRE(solution.twoSum(nums, target) == expected);
}

TEST_CASE("Example 3")
{
    std::vector<int> nums = {3, 3};
    int target = 6;
    Solution solution;
    std::vector<int> expected = {0, 1};
    REQUIRE(solution.twoSum(nums, target) == expected);
}

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);
    return result;
}

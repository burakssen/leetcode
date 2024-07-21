#include "longestsubstring.h"

int Solution::lengthOfLongestSubstring(std::string s)
{
    int n = s.length();
    int ans = 0;
    int index[128] = {0};
    for (int i = 0, j = 0; j < n; j++)
    {
        i = std::max(index[s[j]], i);
        ans = std::max(ans, j - i + 1);
        index[s[j]] = j + 1;
    }
    return ans;
}
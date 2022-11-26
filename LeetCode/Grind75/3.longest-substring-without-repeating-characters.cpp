/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// abcadefg

// counter[char]++
// if counter[char] is 2, start from first instance
// of char + 1, and repeat

// always check for edge cases (empty string, 1 char string of a space)
// in recursion (must include retrun before method call)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(127, -1);
        int start = -1;
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxSize = max(maxSize, i - start);
        }
        return maxSize;
    }
};


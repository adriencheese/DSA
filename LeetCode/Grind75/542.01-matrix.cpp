/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

/* method 1: BFS */ 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        deque<int> visited;
        visited.push_back(mat[0][0]);

        unordered_map<int, int> map;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                while(!visited.empty()) {

                }
            }
        }
        int value;
        find(visited.begin(), visited.end(), value);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
// [[0,0,0],[0,1,0],[1,1,1]]
    vector<int> adjacentCells = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            // method 1: BFS
        queue<pair<int, int>> visited;

        int xMax = mat[0].size(), yMax = mat.size();
        for (int i = 0; i < yMax; i++) {
            for (int j = 0; j < xMax; j++) {
                if (mat[i][j] == 0) {
                        // add all 0 cells to the unvisited queue
                        // perform BFS from these 0 cells
                    visited.emplace(i, j);
                } else {
                        // set all 1 cells to -1 (denote unvisited)
                        // 0 cells don't need to be processed (0 input -> 0 output), marked as visited
                    mat[i][j] = -1;
                }
            }
        }

        while (!visited.empty()) {
                // take front of queue and remove from queue
            auto [y, x] = visited.front();
            visited.pop();

            for (int i = 0; i < 4; i++) {
                int a = y + adjacentCells[i], b = x + adjacentCells[i + 1];
                    // check boundaries; if neighboring cell is not -1 (unvisited), skip
                    // first loop, mat[a][b] != -1 only checks for 0 cells (all 1 cells are -1 at start)
                    // later, if a 1 cell has already been calculated, skip
                if (a < 0 || a == yMax || b < 0 || b == xMax || mat[a][b] != -1) {
                    continue;
                }

                    // set new cell value to: current cell + 1
                mat[a][b] = mat[y][x] + 1;
                    // add cell[a][b] to unvisited queue, bc BFS hasn't been performed on mat[a][b].
                visited.emplace(a, b);
            }
        }
        return mat;
    }
};
// @lc code=end


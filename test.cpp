#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> grid {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));

    for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << "grid: " << grid[i][j] << endl;
        }
    }
}
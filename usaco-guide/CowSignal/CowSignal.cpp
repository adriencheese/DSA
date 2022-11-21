// http://www.usaco.org/index.php?page=viewproblem2&cpid=665

#include <iostream>
using namespace std;

int m, n, K;

main() {
    std::ios::sync_with_stdio(false);
    cin >> m >> n >> K;


    for (int i = 0; i < m; i++) {
        string lines; cin >> lines; 
        for (int j = 0; j < n; i++) {
            for (int k = 0; k < K;k++) {
                cout << lines[j];
            }
            cout << endl;
        }
    }
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int> > list (n);
    vector<int> degree(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        list[a - 1].push_back(b - 1);
        degree[b - 1]++;
    }

    vector<int> zeroes;
    for (int i = 0; i < degree.size(); i++) {
        if (degree[i] == 0) {
            zeroes.push_back(i);
        }
    }

    vector<int> sorted;
    while (!zeroes.empty()) {
        int temp = zeroes.back();
        zeroes.pop_back();
        sorted.push_back(temp);
        
        for (auto i : list[temp]) {
            --degree[i];
            if (degree[i] == 0) {
                zeroes.push_back(i);
            }
        }
    }

    if (sorted.size() == n) {
        for (auto i : sorted) {
            cout << i + 1 << "\n";
        }
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
}
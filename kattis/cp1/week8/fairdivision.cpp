#include <iostream>
#include <vector>

using namespace std;

void check(vector<int>& row) {
    int size = row.size();
    for (int i = size - 1; i > 0; i--) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> row1(n), row2(n);
    for (int i = 0; i < n; i++) {
        cin >> row1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> row2[i];
    }

    for (int i = n - 1; i > 0; i--) {
        if (row1[i] == row1[i - 1]) {
            row1.erase(row1.begin() + i);
            row1.erase(row1.begin() + i - 1);
        }
        cout << i << " ";
    }
    cout << endl;
    for (int i = n - 1; i > 0; i--) {
        cout << i << " ";
    }
}
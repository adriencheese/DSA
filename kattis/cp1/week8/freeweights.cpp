#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

bool can(vector<int>& row1, vector<int>& row2, int mid) {
    int size = row1.size();

    int a_temp = -1, b_temp = -1;
    for(int i = 0; i < size; i++) {
        if (row1[i] <= mid) {
            continue;
        } else if (a_temp == -1) {
            a_temp = row1[i];
        } else if (a_temp == row1[i]) {
            a_temp = -1;
        } else {
            return false;
        }
    }
    for(int i = 0; i < size; i++) {
        if (row2[i] <= mid) {
            continue;
        } else if (b_temp == -1) {
            b_temp = row2[i];
        } else if (b_temp == row2[i]) {
            b_temp = -1;
        } else {
            return false;
        }
    }

    if (a_temp != -1 || b_temp != -1) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int max = 0;
    int n; cin >> n;

    vector<int> row1(n), row2(n);
    for (int i = 0; i < n; i++) {
        cin >> row1[i];
        if (row1[i] > max) {
            max = row1[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> row2[i];
        if (row2[i] > max) {
            max = row2[i];
        }
    }

    int left = 0, right = max, mid = left + (right - left) / 2;

    while (left <= right) {
        // cout << left << ", " << right << ", " << mid << "\n";
        if (can(row1, row2, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
        // cout << "end: " << left << ", " << right << ", " << mid << "\n";
    }

    cout << mid << "\n";

}
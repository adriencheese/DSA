#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    int temp;
    vector<int> available_sizes;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        available_sizes.push_back(temp);
    }

    vector<int> needed;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        needed.push_back(temp);
    }

    sort(available_sizes.begin(), available_sizes.end());
    sort(needed.begin(), needed.end());

    long long total = 0;

    for (auto i : needed) {
        int flag = 0;
        int left = 0, right = available_sizes.size() - 1;
        int best_index = left;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (available_sizes[mid] == i) { // don't need to add to sum if sizes are =
                best_index = mid;
                flag = 1;
                break;
            } else if (available_sizes[mid] < i) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            if (abs(available_sizes[mid] - i) <= abs(available_sizes[best_index] - i)) {
                available_sizes[best_index] - i < 0 ? best_index = mid + 1 : best_index = mid;
            }
        }

        if (flag == 1) {
            continue;
        }
        total += abs(available_sizes[best_index] - i);
    }

    cout << total;
}

// binary search over available paint can sizes in order to find minimum suitable paint can size
// loop this over the needed paint can sizes. 

// M * log(n)
// with pre sorting
// logn + logm + M * logn

// once minimum paint can available is found, find difference, and add to total count
#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> inputs;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        inputs.push_back(temp);
    }

    set<int> dp;
    dp.insert(0);

    bool found = false;

    int check = INT_MAX;

    for (auto i : inputs) {
        vector<int> temp;
        for (auto j : dp) {
            if (i + j == 1000) {
                found = true;
                break;
            }

            if (dp.find(i + j) == dp.end()) {
                if (i + j > 1000) {
                    if (i + j < check) {
                        check = i + j;
                    }
                    continue;
                }
                temp.push_back(i + j);
            }
        }
        if (found) {
            break;
        }

        for (auto j : temp) {
            dp.insert(j);
        }
    }

    if (found) {
        cout << 1000;
    } else if (check - 1000 > 1000 - *dp.rbegin()) {
        cout << *dp.rbegin();
    } else {
        cout << check;
    }

// loop back from dp[1000] to find sol
// check with min value > 1000
}
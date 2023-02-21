#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> inputs;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        inputs.push_back(temp);
    }

    set<int> dp;

    bool found = false;

    int check = INT_MAX;

    for (auto i : inputs) {
        for (auto j : dp) {
            if (i + j == 1000) {
                found = true;
                break;
            }

            if (!dp.contains(i + j)) {
                if (i + j > 1000) {
                    if (i + j < check) {
                        check = i + j;
                    }
                    continue;
                }
                dp.insert(i + j);
            }
        }
        if (found) {
            break;
        }
    }

    set<int>::iterator itr;
    dp.rbegin

// loop back from dp[1000] to find sol
// check with min value > 1000
}
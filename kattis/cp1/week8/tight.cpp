#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<long double, long double> > input;
    long double k, n;
    while (cin >> k >> n) {
        input.push_back(make_pair(k, n));
    }

    vector<long double> output;
    for (auto i : input) {
        vector<vector<int> > dp(i.second, vector<int>(i.first));

        for (int j = 0; j < i.second; j++) {
            for (int k = 0; k < i.first; k++) {
                
            }
        }
    }
}
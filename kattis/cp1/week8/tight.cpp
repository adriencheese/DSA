#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout << std::setprecision(9);

    vector<pair<long double, long double> > input;
    long double k, n;

    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        istringstream ss(line);
        ss >> k >> n;
        input.push_back(make_pair(k, n));
    }

    vector<long double> output;
    for (auto i : input) {
        if (i.first == 0) {
            output.push_back(1);
            continue;
        }

        vector<vector<long double> > dp(i.first + 1, vector<long double>(i.second));

        for (int j = 0; j <= i.first; j++) {
            dp[j][0] = 1;
        }

        for (int j = 1; j < i.second; j++) { // index of word
            for (int k = 0; k <= i.first; k++) { // character
                if (k == 0) {
                    dp[k][j]  = dp[k][j - 1] + dp[k + 1][j - 1];
                } else if (k == i.first) {
                    dp[k][j]  = dp[k][j - 1] + dp[k - 1][j - 1];
                } else {
                    dp[k][j] = dp[k][j - 1] + dp[k - 1][j - 1] + dp[k + 1][j - 1];
                }
            }
        }

        long double words = 0;
        for (int j = 0; j <= i.first; j++) {
            words += dp[j][i.second - 1];
        }

        output.push_back(words / pow(i.first + 1, i.second));
    }

    for (auto i : output) {
        cout << i * 100 << "\n";
    }
}
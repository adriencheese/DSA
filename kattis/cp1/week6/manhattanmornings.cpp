#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> home(4);
    for (int i = 0; i < 4; i++) {
        cin >> home[i];
    }

        // create dp board before inputting errand locations for ease
    int y = abs(home[3] - home[1]);
    int x = abs(home[2] - home[0]);
    
    vector<vector<int> > dp (y + 1, vector<int> (x + 1, 0));

    for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    vector<pair<int, int> > errands(n, make_pair(0, 0));
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == 0) {
            cin >> errands[i / 2].first;
        } else {
            cin >> errands[i / 2].second;

            cout << "pair: " << errands[i / 2].first << ", " << errands[i / 2].second << endl;

            if (errands[i / 2].first > max(home[0], home[2]) ||
                errands[i / 2].second > max(home[1], home[3])) {
                    continue;
            }

            cout << "errand: " << abs(errands[i / 2].second - home[1]) << ", " << abs(errands[i / 2].first - home[0]) << endl;

            dp[abs(errands[i / 2].second - home[1])][abs(errands[i / 2].first - home[0])]++; // multiple errands on same coord
        }
    }

    for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    // if you always take up or right move, total moves will be the same min
    // dp while only traversing this way

    // home to work is the same as work to home

    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
        }
    }

    cout << "here" << endl;
    
    cout << dp[y][x] << "\n";
}
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
    
    vector<vector<int> > dp (y, vector<int> (x, 0));

    vector<pair<int, int> > errands(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cin >> errands[i].first;
        } else {
            cin >> errands[i].second;
            dp[errands[i].second][errands[i].first]
        }
    }

    // if you always take up or right move, total moves will be the same min
    // dp while only traversing this way


    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {

        }
    }
}
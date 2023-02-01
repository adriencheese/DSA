#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    long long count = 0;
    long long temp;

    vector<long long> weights;
    for (int i= 0; i < n; i++) {
        cin >> temp;
        weights.push_back(temp);
    }

    sort(weights.begin(), weights.end());

    long long a, b;

    vector<pair<long long, long long> > mongers;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mongers.push_back(make_pair(b, a));
    }

    sort(mongers.begin(), mongers.end());

    int itr = mongers.size() - 1;

    for (int i = weights.size() - 1; i >= 0; i--) {
        count += weights[i] * mongers[itr].first;
        mongers[itr].second--;

        if (mongers[itr].second == 0) {
            itr--;
            if (itr < 0) {
                break;
            }
        }
    }

    cout << count;
}
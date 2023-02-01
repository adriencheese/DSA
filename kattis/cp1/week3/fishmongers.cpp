#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    long count = 0;
    long temp;

    vector<long> weights;
    for (int i= 0; i < n; i++) {
        cin >> temp;
        weights.push_back(temp);
    }

    sort(weights.begin(), weights.end());

    long a, b;

    vector<pair<long, long> > mongers;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mongers.push_back(make_pair(b, a));
    }

    sort(mongers.begin(), mongers.end());

    int itr = mongers.size() - 1;

 //     fix MULITPLICATION OF INTEGERS OVERLFOWING

    long cd = 100000;
    long xc = 100000;
    long testing = cd * xc;
    cout << testing << endl;

    for (int i = weights.size() - 1; i >= 0; i--) {
        long x = weights[i];
        long y = mongers[itr].first;
        long result = x * y;
        count += result;
        cout << count << ", " << result << endl;
        mongers[itr].second--;

        if (mongers[itr].second == 0) {
            itr--;
        }
    }

    cout << count;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;

    vector<pair<long long, long long> > line;
    vector<long long> timeslots (N, 0);

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end());

    for (int i = N - 1; i >= 0; i--) {
        long long spot = line[i].second;

        while (timeslots[spot] != 0) {
            spot--;
        }

        if (spot < 0) {
            continue;
        } else {
            timeslots[spot] = line[i].first;
        }
    }

    long long count = 0;
    for (auto i : timeslots) {
        count += i;
    }

    cout << count;
}
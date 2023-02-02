#include <iostream>
#include <vector>
#include <algorithm>

// use vector of available times
// sort by most monies, then assign that person to the latest time they can receive money

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;

    vector<pair<int, int> > line;
    vector<int> timeslots (N);

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end());

    
}
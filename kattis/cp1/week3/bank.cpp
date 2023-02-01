#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;

    vector<pair<int, int> > line;

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.push_back(make_pair(b, a));
    }

    sort(line.begin(), line.end());

    long long count = 0;

    for (int i = 0; i < line.size();) {
        int curr_min = line[i].first;
        int max = -1;

        while(line[i].first == curr_min) {
            if (line[i].second > max) {
                max = line[i].second;
            }
            i++;
        }

        count += max;
    }

    cout << count;
}
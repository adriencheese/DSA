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

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.push_back(make_pair(b, a));
    }

    sort(line.begin(), line.end());

    long long count = 0;

    int remaining = line.size();

    int low_index = 0;

    while(remaining > 0) {
        int i = low_index;

        if (line[i].first < 0) {
            i++;
            low_index = i;
            continue;
        }

        low_index = i;
        int curr_min = line[i].first;
        int max = -1;
        int index;

        // cout << "check lowest" << endl;
        while(line[i].first == curr_min || line[i].first < 0) {
            if (line[i].first < 0) {
                i++;
                continue;
            }

            if (line[i].second > max) {
                max = line[i].second;
                index = i;
            }
            i++;
        }

        line[index].first = -1;
        --remaining;

        for (int j = 0; j < line.size(); j++) {
            line[j].first--;
            // cout << "check decrement: " << line[j].first << endl;
            if (line[j].first == -1) {
                --remaining;
            }
        }

        count += max;

        cout << "recap: " << count << ", " << remaining << endl;
        
        for (auto j : line) {
            cout << j.first << ", " << j.second << endl;
        }
        cout << endl;

    }

    cout << count;
}
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

    int remaining = line.size();

    while(remaining > 0) {
        int i = 0;

        if (line[i].first < 0) {
            i++;
            continue;
        }

        int curr_min = line[i].first;
        int max = -1;
        int index;

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

        for (int j = 0; j < line.size(); j++) {
            line[j].first--;
            if (line[j].first == -1) {
                remaining--;
            }
        }

        line[index].first = -1;

        count += max;

        cout << "recap: " << count << ", " << remaining << endl;
        
        for (auto j : line) {
            cout << j.first << ", " << j.second << endl;
        }
        cout << endl;
    }

    cout << count;
}
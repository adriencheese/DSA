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

    for (int i = 0; i < line.size(); i++) {
        cout << "start: " << line[i].first << ", " << line[i].second << endl;

        int curr_min = line[i].first;

        int nested = i;
        int max = -1;

        while(line[nested].first == curr_min) {
            if (line[nested].second > max) {
                max = line[nested].second;
            }
            nested++;
        }

        count += max;
        i = nested;
        cout << i << ": " << count << endl;
    }

    cout << count;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;

    set<pair<int, int> > line;

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.insert(make_pair(b, a));
    }

    sort(line.begin(), line.end());

    long long count = 0;

    // 
    for (int i = 0; i < line.size();) {
        if (line[i].first < 0) {
            continue;
        }

        int curr_min = line[i].first;
        int max = -1;
        int index;
        while(line[i].first == curr_min) {
            line[i].first--;
            if (line[i].second > max) {
                max = line[i].second;
                index = i;
            }
            i++;
        }

        line[index].first = -1;
        count += max;
        
        cout << "recap: " << count << endl;
        for (auto i : line) {
            cout << i.first << ", " << i.second << ", ";
        }
        cout << endl;

    }

    cout << count;
}
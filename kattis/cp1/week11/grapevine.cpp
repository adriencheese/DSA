#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d; cin >> n >> m >> d;

    unordered_map<string, int> skep;

    string name;
    for (int i = 0; i < n; i++) {
        int lvl;
        cin >> name >> lvl;
        skep[name] = lvl;
    }

    unordered_map<string, vector<string> > list;
    for (int i = 0; i < m; i++) {
        cin >> name;
        string out; cin >> out;
        list[name].push_back(out);
        list[out].push_back(name);
    }

    string start;
    cin >> start;

    vector<string> q;
    unordered_map<string, int> visited;

    q.push_back(start);

    int day = 0;
    int count = 0;

    vector<string> temp_q;
    temp_q.push_back(start);

    while (!temp_q.empty()) {
        if (day == d) {
            break;
        }

        q = temp_q;
        temp_q.clear();

        int size = q.size();

        for (int j = 0; j < size; j++) {
            name = q.back();
            q.pop_back();

            for (auto i : list[name]) {
                if (visited[i] >= skep[i]) {
                    continue;
                }
                if (visited[i] == 0) {
                    count++;
                }
                visited[i]++;
                if (visited[i] == skep[i]) {
                    temp_q.push_back(i);
                }
            }
        }
        day++;
    }

    // cout << endl;
    // for (auto i : visited) {
        // cout << i.first << ", " << i.second << endl;
        // count++;
    // }
    
    cout << count << "\n";
}
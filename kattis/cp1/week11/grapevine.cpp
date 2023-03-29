#include <iostream>
#include <vector>
#include <unordered_map>

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
    }

    string start;
    cin >> start;

    int count = 0;
    vector<string> q;
    unordered_map<string, int> visited;

    q.push_back(start);

    for (int i = 0; i < d; i++) {
        if (q.empty()) {
            break;
        }

        int size = q.size();

        for (int j = 0; j < size; j++) {
            name = q.back();
            q.pop_back();

            for (auto i : list[name]) {
                q.push_back(i);
                visited[i]++;
            }
        }
    }

    for (auto i : visited) {
        if (i.second >= skep[i.first]) {
            count++;
        }
    }
    cout << count << "\n";
}
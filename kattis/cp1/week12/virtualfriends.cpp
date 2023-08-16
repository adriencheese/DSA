#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>

// https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
// https://stackoverflow.com/questions/8300125/union-find-data-structure

using namespace std;

int bfs(unordered_map<string, vector<string> > &list, string& a, string& b) {
    queue<string> q;
    set<string> visited;

    q.push(a);
    q.push(b);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string temp = q.front();
            q.pop();

            visited.insert(temp);

            for (auto j : list[temp]) {
                if (visited.find(j) != visited.end()) {
                    continue;
                }
                q.push(j);
            }
        }
    }

    return visited.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {

        unordered_map<string, vector<string> > list;

        int F; cin >> F;
        for (int j = 0; j < F; j++) {
            string a, b; cin >> a >> b;
            list[a].push_back(b);
            list[b].push_back(a);
            cout << bfs(list, a, b) << "\n";
        }
    }
}
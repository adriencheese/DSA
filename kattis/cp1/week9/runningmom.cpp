#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool dfs(string &in, unordered_map<string, vector<string> > &city_list, set<string> &current_loop) {
    if (current_loop.find(in) != current_loop.end()) {
        current_loop.erase(in);
        return true;
    }

    current_loop.insert(in);

    for (auto i : city_list[in]) {
        if (dfs(i, city_list, current_loop)) {
            return true;
        }
    }

    current_loop.erase(in);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    int n; cin >> n;

    unordered_map<string, vector<string> > city_list;

    for (int i = 0; i < n; i++) {
        string first, second;
        cin >> first >> second;

        city_list[first].push_back(second);
    }
    getline(cin, line);

    vector<string> check;

    while (getline(cin, line)) {
        if (line.empty()) break;
        check.push_back(line);
    }

    for (auto i : check) {
        set<string> current_loop;

        if (dfs(i, city_list, current_loop)) {
            cout << i << " safe" << "\n";
        } else {
            cout << i << " trapped" << "\n";
        }
    }
}
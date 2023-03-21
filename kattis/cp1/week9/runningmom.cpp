#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// if multiple edges from a node, as long as one path can loop, it is safe.
// issue: city with multiple edges will get marked safe

// hashmap for city names

void dfs(string &in, unordered_map<string, vector<string> > &city_list, unordered_map<string, int> &safe_status, unordered_map<string, int> &current_loop) {
    // cout << in << ": ";
    // for (auto i : current_loop) {
    //     cout << "("<< i.first << ", " << i.second << "), ";
    // }
    // cout << endl;
    
    if (current_loop[in] == 1) {
        // cout << "safe" << endl;
        for (auto i : current_loop) {
            // cout << i << ", ";
            if (i.second == 1) {
                safe_status[i.first] = 1;
            }
        }
        // cout << endl;

        // current_loop.clear();
        return;
    }

    current_loop[in] = 1;

    for (auto i : city_list[in]) {
        // cout << in << " to " << i << endl;
        dfs(i, city_list, safe_status, current_loop);
    }

    if (!current_loop.empty()) {
        current_loop[in] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;

    int n; cin >> n;

    unordered_map<string, vector<string> > city_list;
    unordered_map<string, int> safe_status;

    for (int i = 0; i < n; i++) {
        string first, second;
        cin >> first >> second;

        city_list[first].push_back(second);
        safe_status[first] = -1;
        safe_status[second] = -1;
    }
    getline(cin, line);

    vector<string> check;

    while (getline(cin, line)) {
        if (line.empty()) break;
        check.push_back(line);
    }

    for (auto i : check) {
        unordered_map<string, int> current_loop;

        if (safe_status[i] == -1) {
            // cout << "checcking\n";
            dfs(i, city_list, safe_status, current_loop);
        }

        // cout << i << ": ";
        // for (auto i : safe_status) {
        //     cout << i.first << ", " << i.second << endl;
        // }
        // cout << endl;

        if (safe_status[i] == 1) {
            cout << i << " safe" << "\n";
        } else {
            cout << i << " trapped" << "\n";
        }
    }
}
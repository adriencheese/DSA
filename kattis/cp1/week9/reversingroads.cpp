#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// check for strongly connected graph
bool bfs(vector<vector<int> > list){
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<int> > >input;

    int test_case = 0;
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        if (line[0] > line[2]) {
            input.push_back(vector<vector<int> >(1));
            input[test_case][0].push_back(-1);
            for (int i = 0; i < (line[2] - '0'); i++) {
                getline(cin, line);
            }

            test_case++;
            continue;
        }

        int roads = line[2] - '0';
        input.push_back(vector<vector<int> >(roads));
        for (int i = 0; i < roads; i++) {
            getline(cin, line);
            input[test_case][line[0] - '0'].push_back(line[2] - '0');
        }
        test_case++;
    }

    for (auto i : input) {
        for (auto j : i) {
            // queue<int> q;
            // vector<int> visited;

            // q.push(j);

            // while (!q.empty()) {
            //     // int children = j[q.front()].size();
            // }


            // break; // check starting only from one node
            for (auto k : j) {
                cout << k << ", ";
            }
        }
        cout << "a" << endl;
    }

}
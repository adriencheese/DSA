#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

bool bfs(vector<vector<int> > &list, int &size) {
    queue<int> q;
    set<int> visited;

    q.push(0);

    while (!q.empty()) {
        int cur_size = q.size();
        for (int i = 0; i < cur_size; i++) {
            int temp = q.front();
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
    if (visited.size() < size) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<int> > > input;
    vector<vector<vector<int> > > reversed;
    vector<vector<vector<int> > > edge_list;
    vector<int> node_count;

    int test_case = 0;
    string line;
    
    while (getline(cin, line)) {
        istringstream ss(line);
        if (line.empty()) {
            break;
        }
        int a, b; ss >> a >> b;
        node_count.push_back(a);

        if (a > b) {
            input.push_back(vector<vector<int> >(1, vector<int>(1, -1)));
            reversed.push_back(vector<vector<int> >(1, vector<int>(1, -1)));
            edge_list.push_back(vector<vector<int> >(1, vector<int>(1, -1)));
            for (int i = 0; i < (b); i++) {
                getline(cin, line);
            }
            test_case++;
            continue;
        }

        int roads = b;
        input.push_back(vector<vector<int> > (a));
        reversed.push_back(vector<vector<int> >(a));
        edge_list.push_back(vector<vector<int> > (roads, vector<int> (2)));
        for (int i = 0; i < roads; i++) {
            getline(cin, line);
            istringstream ss(line);
            ss >> a >> b;
            input[test_case][a].push_back(b);
            reversed[test_case][b].push_back(a);
            edge_list[test_case][i][0] = (a);
            edge_list[test_case][i][1] = (b);
        }
        test_case++;
    }
    for (int i = 0; i < test_case; i++) {
        //cerr << node_count[i] << ' ' << input[i][0][0] << '\n';
        if (node_count[i] == 1) {
            cout << "Case " << i + 1 << ": " << "valid" << "\n";
            continue;
        } else if (node_count[i] > edge_list[i].size()) {
            cout << "Case " << i + 1 << ": " << "invalid" << "\n";
            continue;
        } 

        // int size = input[i].size();
        int edge_size = edge_list[i].size();
        if (bfs(input[i], node_count[i]) && bfs(reversed[i], node_count[i])) {
            cout << "Case " << i + 1 << ": " << "valid" << "\n";
        } else {
            bool flag = false;
            for (int j = 0; j < edge_size ; j++) { // iterate and reverse every edge in list
                // int i_size = input[i][j].size(); // # of connections for this node to loop through
                // for (int k = 0; k < i_size; k++) { // each destination of node j
                    vector<vector<int> > i_temp = input[i];
                    vector<vector<int> > r_temp = reversed[i];

                    int child = edge_list[i][j][1]; // child = destination value, j = root value
                    int root = edge_list[i][j][0];
                    vector<int>::iterator position = find(i_temp[root].begin(), i_temp[root].end(), child);

                    i_temp[root].erase(position); // erase child
                    i_temp[child].push_back(root);

                    vector<int>::iterator pos = find(r_temp[child].begin(), r_temp[child].end(), root);
                    r_temp[child].erase(pos);
                    r_temp[root].push_back(child);

                    if (bfs(i_temp, node_count[i]) && bfs(r_temp, node_count[i])) {
                        cout << "Case " << i + 1 << ": " << root << " " << child << "\n";
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    continue;
                }
            cout << "Case " << i + 1 << ": " << "invalid" << "\n";
        }
    }
}
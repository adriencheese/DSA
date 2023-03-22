#include <iostream>
#include <vector>
#include <string>

using namespace std;

// check for strongly connected graph

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<pair<int, int> > > input;

    int test_case = 0;
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }

        int roads = line[2] - '0';
        input.push_back(vector<pair<int, int> > (roads));
        for (int i = 0; i < roads; i++) {
            getline(cin, line);
            input[test_case][i] = make_pair(line[0] - '0', line[2] - '0');
        }
        test_case++;
    }

    for (auto i : input) {
        if ()
    }

}
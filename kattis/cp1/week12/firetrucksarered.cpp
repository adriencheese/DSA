#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <vector>

using namespace std;

    // unordered_map(int, vector<int>)
// hubs are values of people
// as you iterate through input, set first person as rep of the hub
// if hub already exists, use union find on the representative and new person to check if the 2 points have the same root (invalidates mst)

// in this case, kruskals is finding valid edges as you take input

// if find(1) == find(2) don't add, else add to mst and run merge(1, 2)

/*
1 1
2 1
3 1
4 1
5 5
6 6
*/

/*
17: {1, 4}
10: {1, 2, 3}
5: {2}
22: {3}

*/

int find(int a, vector<int> &id, vector<int> &size) {
    int root = a;
    while (root != id[root]) {
        root = id[root];
    }

    while (a != root) {
        int new_a = id[a];
        id[a] = root;
        a = new_a;
    }

    return root;
}

void merge(int a, int b, vector<int> &id, vector<int> &size) {
    int n = find(a, id, size); // just reset a and b, you don't need the leaves
    int m = find(b, id, size);
    if (n == m) {
        return;
    }

    if (size[n] > size[m]) {
        id[m] = n;
        size[n] += size[m];
    } else {
        id[n] = m;
        size[m] += size[n];
    }
}

int main() {
    int n; cin >> n;

    unordered_map<int, vector<int> > list;
    vector<vector<int> > output;

    vector<int> id (n);
    vector<int> sz (n);

    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        id[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int mi; cin >> mi;
        for (int j = 0; j < mi; j++) {
            int temp; cin >> temp;

            if (list.find(temp) == list.end()) { // hub not found
                list[temp].push_back(i);
            } else {
                int a = find(i, id, sz);
                int b = find(list[temp][0], id, sz);
                if (a != b) {
                    list[temp].push_back(i);
                    output.push_back(vector<int>());
                    output.rbegin()->push_back(i);
                    output.rbegin()->push_back(list[temp][0]);
                    output.rbegin()->push_back(temp);
                    merge(i, list[temp][0], id, sz);
                }
            }
        }
    }

    if (output.size() != n - 1) {
        cout << "impossible" << "\n";
    } else {
        for (auto i : output) {
            cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << "\n";
        }
    }
}
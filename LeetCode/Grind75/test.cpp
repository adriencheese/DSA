#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> test {1, 2, 3, 4};
    vector<vector<int> > sol;

    sol.push_back(sort(vector<int> {test[3], test[1], test[2]}));

    for (auto i : sol[0]) {
        cout << i << endl;
    }
}
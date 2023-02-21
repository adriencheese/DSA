#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main() {
    set<int> dp;

    dp.insert(1);
    dp.insert(2);
    dp.insert(3);

    for (auto i : dp) {
        cout << i << endl;
    }

    cout << INT_MAX - 1000 << endl;

    cout << *dp.rbegin() << endl;
}
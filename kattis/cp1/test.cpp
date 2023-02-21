#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> dp;

    dp.insert(1);
    dp.insert(2);
    dp.insert(3);

    cout << &dp.rbegin() << " - " << *dp.rbegin() << endl;
}
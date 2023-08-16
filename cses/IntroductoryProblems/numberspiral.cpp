#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        ll y, x; cin >> y >> x;

        if (y == x) {
            cout << 1 + (x * (x - 1));
        } else if (y > x) {
            if (y % 2 == 0) {
                cout << (y * y) - (x - 1);
            } else {
                cout << ((y - 1)*(y - 1) + x);
            }
        } else {
            if (x % 2 == 0) {
                cout << ((x - 1)*(x - 1) + y);
            } else {
                cout << (x * x) - (y - 1);
            }
        }
        cout << endl;
    }
}
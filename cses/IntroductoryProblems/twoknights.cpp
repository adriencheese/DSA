#include <iostream>
#include <math.h>

using namespace std;
#define ll long long

int main() {
    int n; cin >> n;

    ll dif = 0;
    for (int i = 1; i <= n; i++) {
        ll square = pow(i, 2);
        
        cout << (square * (square - 1)) / 2 - dif << "\n";

        if (i >= 2) {
            dif += 8 * (i - 1);
        }
    }
}
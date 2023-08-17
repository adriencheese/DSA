#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    if (n == 1) {
        cout << "NO";
        return 0;
    }

    if ((n + 1) % 4 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO";
        return 0;
    }

    cout << n / 2 + 1 << "\n";
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 1 || i % 4 == 2) {
            cout << i << " ";
        }
    }

    cout << "\n" << n / 2 << "\n";
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0 || i % 4 == 3) {
            cout << i << " ";
        }
    }
}
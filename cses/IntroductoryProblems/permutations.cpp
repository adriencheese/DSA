#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1 2 3
    // 3 1 4 2
    // 4 2 3 1 
    // 1 3 5 2 4
    // 5 3 1 4 2
    // 1 3 5 2 4 6
    // 6 4 2 5 3 1
    // 5 3 1 6 4 2
    // 
    int x; cin >> x;
    if (x == 1) {
        cout << "1";
        return 0;
    }
    if (x == 3 || x == 2) {
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i = x - 1; i > 0; i -= 2) {
        cout << i << " ";
    }
    for (int i = x; i > 0; i-= 2) {
        cout << i << " ";
    }
}
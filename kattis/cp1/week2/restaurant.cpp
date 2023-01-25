#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;


//TODO: 

//  fails on first test case
//  if reserve team has broken on each side, which to pick?
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // a = 2, b == 1

    int N = 0; cin >> N;
    while (N != 0) {
        int a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            string line; cin >> line;
            int quantity; cin >> quantity;

            if (line == "DROP") {
                a += quantity;
                cout << "DROP 2 " << quantity << "\n";
            } else {
                if (b >= quantity) {
                    b -= quantity;
                    cout << "TAKE 1 " << quantity << "\n";
                } else {
                    if (b != 0) {
                        cout << "TAKE 1 " << b << "\n";
                        quantity -= b;
                        b = 0;
                    }
                    cout << "MOVE 2->1 " << a << "\n";
                    b = a - quantity;
                    a = 0;
                    cout << "TAKE 1 " << quantity << "\n";
                }
            }
        }
        cout << "\n";
        cin >> N;
    }
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    string n; cin >> n;
    int sol = 1, cur = 0;
    char last;
    for (char c : n) {
        if (last == c) {
            cur++;
            sol = max(sol, cur);
        } else {
            last = c;
            cur = 1;
        }
    }
    
    cout << sol;
}
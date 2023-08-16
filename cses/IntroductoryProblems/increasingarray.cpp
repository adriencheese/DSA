#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll x; cin >> x;
    ll sol = 0, prev = 0;
    for (ll i = 0; i < x; i++) {
        ll cur; cin >> cur;
        if (cur < prev) {
            sol += prev - cur;
            cur = prev;
        }
        prev = cur;
    }
    cout << sol;
}
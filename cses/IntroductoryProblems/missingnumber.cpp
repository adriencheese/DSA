#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    ll s = (n * (n + 1)) / 2;

    for (ll i = 1; i < n; i++)  {
        ll temp; cin >> temp;
        s -= temp;
    }

    cout << s;

}
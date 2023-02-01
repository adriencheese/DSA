#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, c; cin >> h >> c;
    
    multiset<array<long long, 3> > coworkers;

    long long max_annoyance = 0;

    for (int i = 0; i < c; i++) {
        int a, d; cin >> a >> d;
        if (a > max_annoyance) {
            max_annoyance = a;
        }

        coworkers.insert({a + d, a, d});
    }

    multiset<array<long long, 3> >::iterator actual_itr;

    for (int i = 0; i < h; i++) {
        actual_itr = coworkers.begin();

        array<long long, 3> temp = *actual_itr;
        coworkers.erase(actual_itr);

        temp[0] += temp[2];
        temp[1] += temp[2];

        if (temp[1] > max_annoyance) {
            max_annoyance = temp[1];
        }

        coworkers.insert({temp[0], temp[1], temp[2]});

        actual_itr++;
    }

    cout << max_annoyance;
}
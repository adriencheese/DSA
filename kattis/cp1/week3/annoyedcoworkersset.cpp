#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, c; cin >> h >> c;
    
    set<pair<int, int> > coworkers;

    long long max_annoyance = 0;

    for (int i = 0; i < c; i++) {
        int a, d; cin >> a >> d;
        if (a > max_annoyance) {
            max_annoyance = a;
        }

        coworkers.insert(make_pair(a, d));
    }

    set<pair<int, int> >::iterator itr;

    for (int i = 0; i < h; i++) {

        itr = coworkers.begin();
        pair<int, int> temp = *itr;
        coworkers.erase(itr);

        temp.first += temp.second;

        if (temp.first > max_annoyance) {
            max_annoyance = temp.first;
        }

        coworkers.insert(make_pair(temp.first, temp.second));

        itr++;
    }

    cout << max_annoyance;
}
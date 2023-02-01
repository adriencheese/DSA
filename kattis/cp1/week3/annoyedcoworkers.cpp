#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, c; cin >> h >> c;
    
    vector<pair<int, int> > coworkers;

    int max_annoyance = 0;

    for (int i = 0; i < c; i++) {
        int a, d; cin >> a >> d;
        if (a > max_annoyance) {
            max_annoyance = a;
        }

        coworkers.push_back(make_pair(a, d));
    }

    // always start with lowest increase
        // if increase + curr_annoyance > max_annoyance: 
    
    //use a set
        // swap, insert (automatically sorted)

    for (int g = 0; g < h; g++) {
        long best_sum = INT_MAX;
        int index;

        for (int i = 0; i < coworkers.size(); i++) {
            if (coworkers[i].first + coworkers[i].second < best_sum) {
                best_sum = coworkers[i].first + coworkers[i].second;
                index = i;
            }
        }

        coworkers[index].first += coworkers[index].second;
        if (coworkers[index].first > max_annoyance) {
            max_annoyance = coworkers[index].first;
        }
    }

    cout << max_annoyance;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long double l, w; cin >> l >> w;
    long double avg = w / l;
    int mod = (int)w % (int)l;

    if (avg > 26.0 || l > w) {
        cout << "impossible" << "\n";
    } else {
        vector<int> word (l, (int)avg);

        for (int i = 0; i < mod; i++) {
            word[i]++;
        }

        for (int i = 0; i < l; i++) {
            cout << char(word[i] + 96) << "\n";
        }
    }
}
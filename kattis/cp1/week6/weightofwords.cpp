#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, w; cin >> l >> w;

    long long avg = (long long) w / (long long) l;
    cout << avg << endl;
    int mod = w % l;
    cout << mod << endl;

    if (avg >= 26.0) {
        cout << "impossible" << "\n";
    } else {
        vector<int> word (l, (int)avg);

        for (int i = 0; i < mod; i++) {
            word[i]++;
        }

        for (int i = 0; i < l; i++) {
            cout << char(word[i] + 96);
        }
    }
}
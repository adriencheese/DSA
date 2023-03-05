#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int F; cin >> F;

    int total_spaces = 0;
    int max_spaces = 0;
    vector<int> freq(80, 0);

    vector<vector<int> > files(F);
    for (int i = 0; i < F; i++) {
        int lines; cin >> lines;
        vector<int> temp(lines, 0);
        files[i] = temp;
        for (int j = 0; j < lines; j++) {
            cin >> files[i][j];
            freq[files[i][j]]++;
            total_spaces += files[i][j];
            if (files[i][j] > max_spaces) {
                max_spaces = files[i][j];
            }
        }
    }

    int max = 0;
    int tab_space = 0;
    for (int i = 79; i >= 1; i--) { // tab size
        int saved = i * freq[i] - freq[i];
        for (int j = i + 1; j < 80; j++) { // loop through rest of the freq arr to count saved bytes
            saved += (((j / i) * i) - (j / i)) * freq[j];
        }
        if (saved > max) {
            max = saved;
            tab_space = i;
        }
        else if (saved == max) {
            tab_space = i;
            max = saved;
        }
    }

    cout << tab_space << "\n" << max << "\n";
}
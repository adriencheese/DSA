#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    vector<int> max_arr(n);
    int max = input[0];
    max_arr[0] = max;
    for (int i = 1; i < n; i++) {
        if (input[i] > max) {
            max = input[i];
            max_arr[i] = max;
        } else {
            max_arr[i] = max_arr[i - 1];
        }
    }
    
    vector<int> min_arr(n);
    int min = input[n - 1];
    min_arr[n - 1] = min;
    for (int i = n - 2; i >= 0; i--) {
        if (input[i] < min) {
            min = input[i];
            min_arr[i] = min;
        } else {
            min_arr[i] = min_arr[i + 1];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (min_arr[i] == max_arr[i]) {
            count++;
        }
    }

    cout << count;
}
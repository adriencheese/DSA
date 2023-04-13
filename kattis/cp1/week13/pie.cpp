#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

long long can(vector<long long>& input, long double slice) {
    long long num_of_slices = 0;
    for (long long i : input) {
        num_of_slices += (i * i) / slice;
        cout << "inc: " << i*i << ", " << slice << ", " << num_of_slices << endl;
    }
    cout << "can: " << slice << ", " << num_of_slices << endl;
    return num_of_slices;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout << setprecision(10);

    int test_cases; cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        vector<long long> input;
        int N; cin >> N;
        long long F; cin >> F;
        F = 1000 * (F+1);

        long long right = 0;
        int max = 0;
        for (int j = 0; j < N; j++) {
            long long temp; cin >> temp;
            temp *= 1000;
            if (temp > max) {
                max = temp * temp;
                right = temp * temp;
            }
            input.push_back(temp);
        }

        long long left = 0;
        long long mid = 0;
        while (left < right) {
            cout << left << ", " << right << endl;
            mid = right - (right - left) / 2;
            long long val = can(input, (long double)mid);

            if (val >= F) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        cout << ((long long) mid) * M_PI / 1000 << "\n";
    }
}

/*
1
1 10000
3
*/
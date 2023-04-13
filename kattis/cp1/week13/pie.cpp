#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

long long can(vector<long double>& input, long double slice) {
    long long num_of_slices = 0;
    for (long long i : input) {
        num_of_slices += (int)(i / slice);
    }
    return num_of_slices;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;
    cout << setprecision(10);

    int test_cases; cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        vector<long double> input;
        long long N, F; cin >> N >> F;
        F++;

        long double right = -1;
        for (int j = 0; j < N; j++) {
            long double temp; cin >> temp;
            temp *= temp;
            if (temp > right) {
                right = temp;
            }
            input.push_back(temp);
        }

        long double left = 0;
        long double mid = 0;
        while (left < right) {
            mid = right - (right - left) / 2;
            long long val = can(input, (long double)mid);

            if (val >= F) {
                left = mid + .0001;
            } else {
                right = mid - .0001;
            }
        }
        cout << (mid) * M_PI << "\n";
    }
}
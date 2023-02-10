#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m, a, c, start;
    cin >> n >> m >> a >> c >> start;

    vector<int> sequence;
    sequence.push_back((a * start + c) % m);
    for (size_t i = 1; i < n; i++) {
        sequence.push_back((a * (sequence[i - 1]) + c) % m);
    }

    long long count = 0;

    for (auto i : sequence) {
        int left = 0, right = n - 1, mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (sequence[mid] == i) {
                count++;
                break;
            } else if (sequence[mid] > i) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    cout << count;
}
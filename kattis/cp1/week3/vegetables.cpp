#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int min = INT_MAX;
    int max = INT_MIN;

    double T; cin >> T;
    int N; cin >> N;

    vector<int> vegetables;

    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        vegetables.push_back(temp);
        if (temp > max) {
            max = temp;
        }
        if (temp < min) {
            min = temp;
        }
    }

    long ratio = max / min;

    while ()

}

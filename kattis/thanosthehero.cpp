#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> pop (N, 0);
    int cornercase, count;
    cornercase = count = 0;

    for (int i = 0; i < N; i++) {
        cin >> pop[i];
    }

    for (int i = 0; i < N-1; i++) {
        if (pop[i] > pop[i+1]) {
            count += pop[i]-pop[i+1]+1;
        }
    }

    for (int i = 0; i < N; i++) {
        cornercase += pop[i];
    }
    
    if (cornercase == 1) {
        count = 1;
    }

    cout << count;
    return 0;
}
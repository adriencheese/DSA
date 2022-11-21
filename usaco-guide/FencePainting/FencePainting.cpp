#include <iostream>
using namespace std;

int main() {
    int f1, f2, c1, c2;
    

    cout << "farmers 1 and 2\n";
    cin >> f1 >> f2;

    cout << "bessie 1 and 2\n";
    cin >> c1 >> c2;

    int total = (f2-f1) + (c2-c1); // the sum of the two intervals
    int intersection = max(min(f2,c2) - max(f1,c1),0); // subtract the intersection
    int ans = total - intersection;

    cout << ans << "\n";
}
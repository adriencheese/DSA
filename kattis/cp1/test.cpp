#include <iostream>

using namespace std;

int power1(int a, int n, int &mults, int &fcalls) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    } else {
        mults++; fcalls++;
        cout << "n: " << n << " ";
        cout << "mults: " << mults << " fcalls: " << fcalls << endl;
        return a * power1(a, n - 1, (mults), (fcalls));
    }
}

int main() {
    int mults, fcalls = 0;
    int a = 2;
    int n = 5;
    power1(a, n, mults, fcalls);
    cout << mults << ", " << fcalls << endl;
}
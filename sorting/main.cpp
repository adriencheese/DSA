#include <iostream>
#include <vector>
#include "bubble.cpp"

using namespace std;

int main() {
    vector<int> test = {0, 1, 6, 23, 1242, 2, 23, 5, 7, 8, 45, 3456, 345, 2, 3, 4, 8, 8, 11};
    cout << bubbleSort(test) << endl;
}
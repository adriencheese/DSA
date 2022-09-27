#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    // USING MAP, fails on 
    // int N, H, sumCitations, minusCitations = 0; cin >> N;
    // vector<int> input;
    // map<int, int> counts;
    
    // for (int i = 0; i < N; i++) {
    //     int K; cin >> K;
    //     input.push_back(K);
    // }

    // sort(input.begin(), input.end());

    // for (int i = 0; i < input.size(); i++) {
    //     counts[input[i]]++;
    // }

    // sumCitations = input.size();

    // for (auto count : counts) {
    //     if (count.first <= (sumCitations - minusCitations)) {
    //         H = count.first;
    //     }
    //     minusCitations += count.second;
    // }
    // cout << H;

    int N, H = 0; cin >> N;
    vector<int> input; 

    for (int i = 1; i <= N; i++) {
        int K; cin >> K;
        input.push_back(K);
    }

    sort(input.begin(), input.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        if (i < input[i]) {
            H = i+1;
        }
    }

    cout << H;
}
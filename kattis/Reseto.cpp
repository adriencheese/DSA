#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, count;
    
    cin >> N >> K;
    count = 0;
    
    vector<bool> arr (N+1, true);
    
    for (int i = 2; i <= N; i++) {
        if (arr[i]) {
            int j = i;            
            while (j <= N) {
                if(arr[j] == 1) {
                    arr[j] = 0;
                    count++;
                }
                if (count == K) {
                    cout << j << endl;
                    return 0;
                }
                j+=i;
            }
        }
    }
}
  
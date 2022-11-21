// http://www.usaco.org/index.php?page=viewproblem2&cpid=760
// https://usaco.guide/problems/usaco-760-the-bovine-shuffle/solution

#include <iostream>
using namespace std;


const int MAX = 100;
int shuffle[MAX];
int cowid[MAX];


int find(int n, int x) {
    for (int i = 0; i < n; i++) {
        // if element at index i == index, then return the index
        if (shuffle[i] == x) {
            return i;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout); 

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> shuffle[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cowid[i];
    }

    //loop through 3 unshuffles
    for (int i = 0; i < 3; i++) {
        //temp arr for unshuffles
        int temp[MAX];
        for (int j = 1; j <= n;j++) {
            //e is the index of where the cow in j index came from (what index it needs to go to in temp arr)
            int e = find(n, j);

            //populate the temp arr with the unswapped cowid's
            temp[e] = cowid[j-1];
        }
        
        //assign temp to cowid (temp is now the one-step unshuffled)
        for (int j = 0; j < n; j++) {
            cowid[j] = temp[j];
        }

    }

    for (int i = 0; i < n; i++) {
        cout << cowid[i] << '\n';
    }
}


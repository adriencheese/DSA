//http://www.usaco.org/index.php?page=viewproblem2&cpid=856
//https://usaco.guide/problems/usaco-856-the-bucket-list/solution

#include <iostream> 
using namespace std;
int event[1001];

int main() {
    ios_base::sync_with_stdio(false);

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int start; cin >> start;
        int end ; cin >> end;
        int bucketAmt; cin >> bucketAmt;

        // when we loop through event, assigning each 
        // element to the change in buckets being used.
        // += is the same as = bucketAmt (bc elements in event init'd to 0)
        // -= is the same as = -bucketAmt
        event[start] = bucketAmt;
        event[end] = -bucketAmt;
    }

//test to print out the event array 
    // for (int i = 0; i < 20; i++) {
    //     cout << event[i];
    // }

    // cur = sum at each element in event array
    // res = max cur value
    int cur = 0, res = 0;


    for (int i = 0; i < 1001; i++) {
        // loop through event and sum all values
        cur+=event[i];
        res=max(cur, res);
    }

    cout << res << endl;
    return 0;
}
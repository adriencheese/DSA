//http://www.usaco.org/index.php?page=viewproblem2&cpid=917

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<pair<int, int>> road;
vector<string> seg;

int preMin = 0;
int m
int preMaximum(int n) {
    if(seg[n+1]=="none") {
        return max(preMaximum(n+1), maxLow);
    }
    else {
        return 1;
    }
}

int preMinimum(int n) {
    if(seg[n+1]=="none") {
        return max(preMinimum(n+1), maxLow);
    }
    else {
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // freopen("traffic.in", "r", stdin);
    // freopen("traffic.out", "w", stdout);
    int n; cin >> n;

    cout << "test" << endl;

    for (int i = 0; i < n; i++) {
        string segment; cin >> segment;
        pair<int, int> range; cin >> range.first >> range.second;

        seg.push_back(segment);

        road.push_back(range);
    }

    // print through vectors
    // for (int i = 0; i < road.size(); i++) {
    //     cout << road[i].first << ", " << road[i].second << endl;
    // }
    
    int preLower, postLower = 0;

    for (int i = 0; i < road.size(); i++) {
        if (seg[i]=="on") {
            preLower -= road[i].first;
            postLower -= road[i].second;
        }

        else if (seg[i]=="none") {
            preMaximum(i);
        }

        else {
            preLower += road[i].first;
            postLower += road[i].second;
        }
    }

}


//http://www.usaco.org/index.php?page=viewproblem2&cpid=568

#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M; cin >> N >> M;

    vector<int> RoadLimit(100);
    int position = 0;

    for (int i = 0; i < N; i++) {
        int length, speed;
        cin >> length >> speed;
        for (int j = position; j < position+length; j++) {
            RoadLimit[j] = speed;
        }
        position += length;
    }

//bessie's metrics
    vector<int> Bessie(100);
    position = 0;
    for (int i = 0; i < N; i++) {
        // loop through each mile of the road (vector) and record speed
        int length, speed;
        cin >> length >> speed;
        for (int j = position; j < position+length; j++) {
            Bessie[j] = speed;
        }
        position += length;
    }

//loop through road, compare speed and limit
    int worst = 0;
    for (int i = 0; i < 100; i++) {
        worst = max(worst, Bessie[i]-RoadLimit[i]);
    }
    cout << worst;
    return 0;
}
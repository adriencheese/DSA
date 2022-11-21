//http://www.usaco.org/index.php?page=viewproblem2&cpid=735

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;

    vector<int> yes;

    //best case
    if (x == y) {
        cout << 0 << endl;
        return 0;
    }

        // if farmer john is left of bessie
    else if (x < y) {
        int step = 1;
        while (x+step < y) {
            //add each position (after each step) to the vector
            yes.push_back(x+step);
            //multiply for the distance of the next step (double and opposite dir)
            step*=-2;
        }

        // because while(x+step < y) is true before the last step distance is added to the vector, add after loop
        yes.push_back(x+step);

        // first position is x+step, so instead of finding difference of first term and x (first step)
        // to the summation loop, just start with 1 here
        int DistanceTravelled=1;

        //loop through vector and add the differences between the distances
        for(int i = 0; i < yes.size()-1; i++) {
            DistanceTravelled+=abs(yes[i]-yes[i+1]);
        }

        // for cases where the last step overshoots where bessie is
        DistanceTravelled-=abs(yes[yes.size()-1]-y);

        // print sol
        cout << DistanceTravelled;
        return 0;
    }
     
    else {
        int step = 1;

        while (x+step > y) {
            yes.push_back(x+step);
            step*=-2;
        }

        yes.push_back(x+step);

        int DistanceTravelled=1;

        for(int i = 0; i < yes.size()-1; i++) {
            DistanceTravelled+=abs(yes[i]-yes[i+1]);
        }

        DistanceTravelled-=abs(yes[yes.size()-1]-y);

        cout << DistanceTravelled;
        // cout << DistanceTravelled-abs(yes[yes.size()-1]-y) << endl;
        return 0;
    }
    return 0;
}
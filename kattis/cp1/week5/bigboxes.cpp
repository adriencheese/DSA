#include <iostream>
#include <vector>

using namespace std;

int can(vector<int> &boxes, int &mid, int &k) {
// if boxes_count > k and haven't finished loop
// if the boxes_count = k and curr_weight >= mid, return over;
// if reach end of loop and boxes_count <= k, return under;


// check if any box_weight > mid

// when is there a box_weight > mid (mid is invalid)
    // when boxes_count > k (you don't reach end of loop)
        // this means that there were too many boxes greater than mid

// when is mid valid?
    // when you reach end of loop and k < boxes_count

    int curr_weight = 0, boxes_count = 1;
    for (auto i : boxes) {
        if (i > mid) {
            return -1;
        }
        
        curr_weight += i;

        if (curr_weight > mid) {
            boxes_count++;
            curr_weight = i;
            if (boxes_count > k) {
                return -1; // mid is too low, check higher value
            }
        }
    }

    return 1; // mid is valid, check smaller value
}

int main()
{
    // answer space: all possible combinations of consecutive items
        // can function checks if is possible to find solution where all boxes are less than current weight being checked
        // to check if sol is correct, use greedy to go from left to right and check if adding the next box goes over the value you're checking
    int n, k; cin >> n >> k;

    int right = 0;

    vector<int> boxes (n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
        right += boxes[i];
    }

    int left = 0;

    while (left < right) {
        int mid = left + (right - left) / 2; // possible value of minimum heaviest box

        if (can(boxes, mid, k) > 0) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
}

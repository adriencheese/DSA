/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
double findDistance(int x, int y) {
    double output = sqrt(pow(x, 2) + pow(y, 2));
    return output;
}

string coordToString(int x, int y) {
    string str = to_string(x + y);
    cout << str << endl;
    return str;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> solution;
        
        vector<pair<double, vector<int>>> combined;
        map<vector<int>, int> counter;


            // # of times each vector appears in the point list for counter
            // add vector:distance pairs to combined vector

        for (auto it : points) {
            counter[it]++;
            combined.push_back(make_pair(findDistance(it[0], it[1]), it));
        }

        sort(combined.begin(), combined.end());

        for (auto it : combined) {
            for (auto const&[keyB, valueB] : counter) {
                if (it.second == keyB) {
                    for (int i = 0; i < valueB; i++) {
                        solution.push_back(keyB);
                        k--;
                        if (k == 0) {
                            break;
                        }
                    }
                }
                if (k == 0) {
                    break;
                }
            }
            if (k == 0) {
                break;
            }
        }
        return solution;
    }
};
// @lc code=end


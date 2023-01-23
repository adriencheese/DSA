#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int dfs(vector<string> &color_list, unordered_map<string, string> &color_pairs, vector<string> &temp, int current_index) {
    for (int i = current_index; i < color_list.size(); i++) {
        if (color_pairs[temp[temp.size() - 1]]  == ) {

        }
        temp.push_back(color_list[i])
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        
        vector<string> color_list;
        for (int j = 0; j < N; j++) {
            string color; cin >> color;
            color_list.push_back(color);
        }

        unordered_map<string, string> color_pairs;
        int M; cin >> M;
        for(int j = 0; j < M; j++) {
            string color1, color2; cin >> color1 >> color2;

            color_pairs[color1] = color2;
            color_pairs[color2] = color1;
        }

        int count = 0;
        for (auto i : color_list) {
            
        }
    }
}
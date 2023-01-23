#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string best_painting = "";

void dfs(vector<string> &color_list, unordered_map<string, string> &color_pairs, vector<string> &curr_seq, unordered_map<string, int> &tracking, int &count) {
    if (curr_seq.size() == color_list.size()) {
      if (count == 0) {
        for (auto i : curr_seq) {
          best_painting += i;
        }
      }

      tracking.clear();
      count++;
      return;
    }

    for (int i = 0; i < color_list.size(); i++) {
        if (tracking[color_list[i]] > 0) {
            continue;
        }
        if (curr_seq.size() && color_pairs[curr_seq[curr_seq.size() - 1]]  == color_list[i]) {
            continue;
        }

        curr_seq.push_back(color_list[i]);
        tracking[color_list[i]]++;
        dfs(color_list, color_pairs, curr_seq, tracking, count);
        curr_seq.pop_back();
        tracking[color_list[i]]--;
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
        vector<string> curr_seq;

        unordered_map<string, int> tracking;
        dfs(color_list, color_pairs, curr_seq, tracking, count);
        cout << count << "\n" << best_painting << "\n";
        best_painting = "";
    }
}

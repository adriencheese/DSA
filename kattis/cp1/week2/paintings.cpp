#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string best_painting = "";

void dfs(unordered_map<string, int> &color_list, unordered_map<int, vector<int> > &color_bans, vector<string> &curr_seq, unordered_map<string, int> &tracking, int &count) {

    if (curr_seq.size() == color_list.size()) {
      if (count == 0) {
        for (auto i : curr_seq) {
          best_painting += i; best_painting += " ";
        }
      }

      count++;
      return;
    }

    for (auto i : color_list) {
        if (tracking[i.first] > 0) {
            continue;
        }

        if (color_bans[i.second][i.second] == -1) {
            continue;
        }

        curr_seq.push_back(i.first);
        tracking[i.first] = 1;
        dfs(color_list, color_bans, curr_seq, tracking, count);
        curr_seq.pop_back();
        tracking[i.first] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        
        vector<string> temp;
        unordered_map<string, int> color_list;
        
        for (int j = 0; j < N; j++) {
            string color; cin >> color;
            temp.push_back(color);
        }

        for (int j = temp.size() - 1; j >=0; j--) {
            color_list[temp[j]] = j;
        }

        unordered_map<int, vector<int> > color_bans;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                color_bans[i].push_back(j);
            }
        }

        int M; cin >> M;
        for(int j = 0; j < M; j++) {
            string color1, color2; cin >> color1 >> color2;
            color_bans[color_list[color1]][color_list[color2]] = -1;
            color_bans[color_list[color2]][color_list[color1]] = -1;
        }

        int count = 0;
        vector<string> curr_seq;

        unordered_map<string, int> tracking;
        dfs(color_list, color_bans, curr_seq, tracking, count);
        cout << count << "\n" << best_painting << "\n";
        best_painting = "";
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string best_painting = "";

void dfs(unordered_map<int, string> &color_list, unordered_map<string, int> &reverse, unordered_map<int, vector<int> > &color_bans, vector<string> &curr_seq, unordered_map<int, int> &tracking, int &count) {
    if (curr_seq.size() == color_list.size()) {
      if (count == 0) {
        for (auto i : curr_seq) {
          best_painting += i; best_painting += " ";
        }
      }

      count++;
      return;
    }

    for (int i = 0; i < color_list.size(); i++) {
        if (tracking[i] > 0) {
            continue;
        }

        if (curr_seq.size() > 0 && color_bans[reverse[curr_seq[curr_seq.size() - 1]]][i] == -1) {
            continue;
        }

        curr_seq.push_back(color_list[i]);
        tracking[i] = 1;
        dfs(color_list, reverse, color_bans, curr_seq, tracking, count);
        curr_seq.pop_back();
        tracking[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        
        unordered_map<int, string> color_list;
        unordered_map<string, int> reverse;

        for (int j = 0; j < N; j++) {
            string col; cin >> col;
            color_list[j] = col;
            reverse[col] = j;
        }

        unordered_map<int, vector<int> > color_bans;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                color_bans[j].push_back(k);
            }
        }

        int M; cin >> M;
        for(int j = 0; j < M; j++) {
            string color1, color2; cin >> color1 >> color2;
            color_bans[reverse[color1]][reverse[color2]] = -1;
            color_bans[reverse[color2]][reverse[color1]] = -1;
        }

                // debug color_bans
        // for (int j = 0; j < N; j++) {
        //     cout << j << ": " << endl;
        //     for (int k = 0; k < N; k++) {
        //         cout << color_bans[j][k] << ", ";
        //     }
        //     cout << endl;
        // }

        int count = 0;
        vector<string> curr_seq;

        unordered_map<int, int> tracking;
        dfs(color_list, reverse, color_bans, curr_seq, tracking, count);
        cout << count << "\n" << best_painting << "\n";
        best_painting = "";
    }
}

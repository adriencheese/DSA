#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string best_painting = "";

void dfs(vector<string> &color_list, vector<pair<string, string> > &color_bans, vector<string> &curr_seq, unordered_map<string, int> &tracking, int &count) {
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
        if (tracking[color_list[i]] > 0) {
            continue;
        }

        int cont_flag = 0;
        for (int j = 0; j < color_bans.size(); j++) {
            if (curr_seq.size() == 0) {
                break;
            }
            
            if (color_bans[j].first == curr_seq[curr_seq.size() - 1] && color_list[i] == color_bans[j].second) {
                cont_flag = 1;
                break;
            } else if (color_bans[j].second == curr_seq[curr_seq.size() - 1] && color_list[i] == color_bans[j].first) {
                cont_flag = 1;
                break;
            }
        }

        if (cont_flag) {
            continue;
        }

        curr_seq.push_back(color_list[i]);
        tracking[color_list[i]] = 1;
        dfs(color_list, color_bans, curr_seq, tracking, count);
        curr_seq.pop_back();
        tracking[color_list[i]] = 0;
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

        vector<pair<string, string> > color_bans;
        int M; cin >> M;
        for(int j = 0; j < M; j++) {
            string color1, color2; cin >> color1 >> color2;

            color_bans.push_back(make_pair(color1, color2));
        }

        int count = 0;
        vector<string> curr_seq;

        unordered_map<string, int> tracking;
        dfs(color_list, color_bans, curr_seq, tracking, count);
        cout << count << "\n" << best_painting << "\n";
        best_painting = "";
    }
}

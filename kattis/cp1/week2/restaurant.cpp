#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;


//TODO: 

//  fails on first test case
//  if reserve team has broken on each side, which to pick?
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int temp, N, dmg, rsv; cin >> N >> dmg >> rsv;
    int dmg_size = dmg;
    vector<int> dmg_teams;
    unordered_map<int, int> rsv_teams;

    for (int i = 0; i < dmg; i++) {
        cin >> temp;
        dmg_teams.push_back(temp);
    }

    for (int i = 0; i < rsv; i++) {
        cin >> temp;
        rsv_teams[temp]++;
    }

    for (int i = 0; i < dmg_size; i++) {
        if (rsv_teams[dmg_teams[i]] == 1) { // if dmg'd team has a reserve, cancel out
            rsv_teams[dmg_teams[i]]--;

            dmg--;
        } else if (rsv_teams[dmg_teams[i] - 1] == 1) {
            rsv_teams[dmg_teams[i] - 1]--;
            dmg--;
        } else if (rsv_teams[dmg_teams[i] + 1] == 1) {
            rsv_teams[dmg_teams[i] + 1]--;
            dmg--;
        }
    }

    cout << dmg;
}
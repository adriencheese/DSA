#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fstream FILE("input.txt");
    string line;

    int n; FILE >> n;
    getline(FILE, line);

    vector<pair<string, string> > list (n);

    for (int i = 0; i < n; i++) {
        FILE >> list[i].first >> list[i].second;
        cout << "check: " << list[i].first << list[i].second << endl;
    }

    vector<string> check;
    FILE >> line;
    check.push_back(line);

    while (FILE >> line) {
        check.push_back(line);
    }


    
}
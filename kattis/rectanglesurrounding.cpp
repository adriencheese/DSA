#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int a, b, c, d;

    while (n != 0) {
        std::vector<std::vector<int> > board (501, std::vector<int>(501, 0));
        int area = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> a >> b >> c >> d;
            
            for (int i = b; i < d; i++) {
                for (int j = a; j < c; j++) {
                    board[i][j] = 1;
                }
            }
        }

        for (auto i : board) {
            for (auto j : i) {
                area += j;
            }
        }

        std::cout << area << "\n";
        std::cin >> n;
    }
}
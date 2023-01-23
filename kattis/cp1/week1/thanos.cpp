#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T; std::cin >> T;

    for (int i = 0; i < T; i++) {
        long long P, R, F;
        std::cin >> P >> R >> F;
        long long count = 0;

        while (P <= F) {
            count++;
            P *= R;
        }
        std::cout << count << "\n";
    }
}
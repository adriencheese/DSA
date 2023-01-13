#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    std::vector<std::string> list;

    for (int i = 0; i < N; i++) {
        std::string str; std::cin >> str;
        list.push_back(str);
    }

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> a >> b;
        
        list[a - 1] += (list[b - 1]);
        list[b - 1].clear();
    }

    std::cout << list[a - 1] << "\n";
}
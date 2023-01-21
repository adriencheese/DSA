#include <iostream>
#include <vector>

void print_sol(std::vector<std::vector<int> > &order, std::vector<std::string> &list, int last_index) {
    std::cout << list[last_index];
    for (auto i : order[last_index]) {
        print_sol(order, list, i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string res;

    int N; std::cin >> N;
    std::vector<std::string> list (N + 1);

    for (int i = 1; i <= N; i++) {
        std::string str; std::cin >> str;
        list[i] = str;
    }

    int a = 1, b;
    std::vector<std::vector<int> > order (N + 1, std::vector<int>());

    for (int i = 0; i < N - 1; i++) {
        std::cin >> a >> b;
        
        order[a].push_back(b);
    }
    
    print_sol(order, list, a);
}
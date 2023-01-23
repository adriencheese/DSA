#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    double pi = 3.141592654;
    
    double r, m, c, q;
    std::cin >> r;
    while (r != 0) {
        std::cin >> m; std::cin >> c;
        q = c / m;
        std::cout << r * r * pi << " " << 4 * r * r * q << "\n";
        std::cin >> r;
    }
}
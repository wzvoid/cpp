#include "my_stl/wz_string.h"

int main() {
    wz_string p = "void wz", w;
    w = p;
    std::cin >> w;
    std::cout << w.length() << std::endl;
    std::cout << w.empty() << std::endl;
    std::cout << w << std::endl;
    return 0;
}
#include "my_stl/wz_string.h"

int main() {
    wz_string a = "wz", b="void", c;
    c = a + b;
//    std::cin >> w;
    std::cout << a.length() << std::endl;
    std::cout << a.empty() << std::endl;
    std::cout << c << std::endl;
//    std::cout << (w + p).length() << std::endl;
    return 0;
}
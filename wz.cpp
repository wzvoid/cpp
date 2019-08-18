#include "my_stl/wz_string.h"
#include <iostream>
int main() {
//    wz_string p = "void ", w = "wz";
//    w = p;
//    std::cin >> w;
//    std::cout << w.length() << std::endl;
//    std::cout << w.empty() << std::endl;
//    std::cout << w + p << std::endl;
    int sum=0,value=0;
    while(std::cin >> value)
        sum += value;
    std::cout << sum;
    return 0;
}
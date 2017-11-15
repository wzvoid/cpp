#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

template<class T>
T func(T x, T y) {
    return x * x + y * y;
}

int main() {
    cout << func(1.02, 2.07);
    return 0;
}

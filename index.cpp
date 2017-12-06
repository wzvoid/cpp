#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("/home/wz/CLionProjects/cpp/xm.jpg");
    namedWindow("test");
    imshow("test", img);
    waitKey(0);
    return 0;
}

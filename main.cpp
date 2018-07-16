#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("/home/wz/CLionProjects/cpp/111.jpg");
    rectangle(img, cvPoint(72, 79), cvPoint(232, 273), cvScalar(0, 0, 255), 2);
    namedWindow("test");
    imshow("test", img);
    waitKey(0);
}
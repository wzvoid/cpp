#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat in = imread("/Users/wzvoid/CLionProjects/cpp/xm.jpg"), out;
    namedWindow("xm");
    imshow("xm", in);
    waitKey(0);
    return 0;
}

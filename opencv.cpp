#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    //显示创建Mat对象的几种方法
    // <<运算符只对二维矩阵有效
    Mat m1(10, 10, CV_8UC3, CvScalar(0, 0, 255)); //CV_8UC3 = CV_[8 bit][unsigned][char][3 channels]
    int sz[3]={2,2,2};
    Mat m2(3,sz,CV_8UC3,CvScalar(0,0,255));//三维 每一维的尺寸
    Mat m3;
    m3.create(10, 10, CV_8UC3);
    Mat m4 = Mat::eye(10, 10, CV_8UC1);// ones(), zeros()
    Mat RowClone = m4.row(1).clone();


//    Mat r = imread("/home/wz/CLionProjects/cpp/200-200.jpg", 1);
//    格式化输出
    Mat r = Mat(5,3,CV_8UC3);
    randu(r, 0, 255);
    cout << "默认风格:" << r << ";" << endl << endl;
    cout << "Python风格:" << format(r, Formatter::FMT_PYTHON) << ";" << endl << endl;
    cout << "逗号风格:" << format(r, Formatter::FMT_PYTHON) << ";" << endl << endl;
    cout << "Numpy风格:" << format(r, Formatter::FMT_NUMPY) << ";" << endl << endl;
    cout << "C风格:" << format(r, Formatter::FMT_C) << ";" << endl << endl;

    //Point Scalar Size Rect


//    BGR顺序
//    Mat img(500,500,CV_8UC3,CvScalar(0,0,255));


//    namedWindow("test");
//    imshow("test", img);
//    waitKey(0);
//    cout << img;
    return 0;
}
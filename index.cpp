#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Employee {
public:
    int m1;

    Employee(int e1) : m1(e1) {}
};

class Manager1 : public Employee {
public:

    int m1;

    Manager1() = default;

    Manager1(int m1) : Employee(123), m1(m1) {}
};


int main() {
    Employee *m = new Manager1(90);

    return 0;
}

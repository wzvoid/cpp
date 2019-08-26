//
// Created by 王振 on 2019/8/26.
//

#include <iostream>
#include <thread>

using namespace std;

void myprint() {
    cout << "我开始了" << endl;
    ///
    cout << "我结束了" << endl;
}

int main() {
    thread myobj(myprint);
    myobj.join();
    cout << "I love China!" << endl;
}
//
// Created by Administrator on 2019/9/26.
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

template<class T>
class SharedPtr {
public:
    explicit SharedPtr(T *ptr) : _ptr(ptr), _pCount(new int(1)) {}

    SharedPtr(const SharedPtr<T> &ap) : _ptr(ap._ptr), _pCount(ap._pCount) {
        ++(*_pCount);
    }

    SharedPtr<T> &operator=(const SharedPtr<T> &ap) {
        if (_ptr != ap._ptr) {
            if (--(*_pCount) == 0) {
                delete _ptr;
                delete _pCount;
            }
            _ptr = ap._ptr;
            _pCount = ap._pCount;
            ++(*_pCount);
        }
        return *this;
    }

    ~SharedPtr() {
        if (--(*_pCount) == 0) {
            delete _ptr;
            delete _pCount;
            cout << "~SharedPtr()" << endl;
        }
    }

    T &operator*() {
        return *_ptr;
    }

    T *operator->() {
        return _ptr;
    }

private:
    T *_ptr;
    int *_pCount;
};


void TestSharedPtr() {
    SharedPtr<int> sp1(new int(10));
    SharedPtr<int> sp2(sp1);
    sp1 = sp2;
}

void replaceSpace(char *str, int length) {
    if (!str)
        return;
    int count = 0;
    for (int i = length; i >= 0; --i) {
        if (str[i] == ' ') {
            ++count;
            for (int j = length + 2 * count; j >= i + 2; --j) {
                str[j] = str[j - 2];
            }
            str[i] = '%';
            str[i + 1] = '2';
            str[i + 2] = '0';
        }
    }
}

int main() {
    TestSharedPtr();
    return 0;
}

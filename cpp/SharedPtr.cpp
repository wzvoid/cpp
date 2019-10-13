//
// Created by Administrator on 2019/9/26.
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unistd.h>

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

int main() {
//    TestSharedPtr();
    pid_t pid = vfork();
    if (pid == 0) {
        printf("child process\n");
        _exit(0);
    } else if (pid > 0)
        printf("father process!\n");
    else
        cerr << "error!" << endl;
    printf("out\n");
    return 0;
}

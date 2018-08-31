#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main() {
    allocator<string> alloc;  // 定义了一个可以分配string的allocator对象
    auto const p=alloc.allocate(5);  //分配n个未初始化的string内存，即为n个空string分配了内存，当然正如上面所说，分配的内存是原始的，未构造的。
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'w');
    alloc.construct(q++, "we are");
    q = p;
    cout << *(++q);
    return 0;
}
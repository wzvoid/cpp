#include<iostream>
#include<string>
#include<vector>

using namespace std;

// 基类 start
class Quote {
public:
    Quote() = default;

    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}

    string isbsn() const { return bookNo; }

    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};
// 基类 end

// 派生类 start
class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;

    Bulk_quote(const string &book, double p, size_t qty, double disc) :
            Quote(book, p), min_qty(qty), discount(disc) {}; // 父类成员使用父类的构造函数。先初始化基类部分，再按照声明顺序依次初始化派生类的成员。
    double net_price(size_t) const override; // 这边要 override

    ~Bulk_quote() override = default;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const { // 这边就不要 override 了
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
// 派生类 end

int main() {
    Quote *q = new Bulk_quote("wz", 2.0, 3, 4.0);
    cout << q->net_price(4);
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct JHClass { // 聚合类
	int a;
	double b;
	string c;
};

//******类定义 start
class Sales {
	// 友元函数声明
	friend Sales add(const Sales&, const Sales&);
	friend ostream &print(ostream&, const Sales&);
	friend istream &read(istream&, Sales&);
public:
	Sales() = default;
	Sales(const Sales&); // 合成拷贝构造函数
	Sales& operator=(const Sales&); // 合成拷贝赋值运算符
	explicit Sales(const string &bn) :Sales(bn, 0, 0.0) { cout << "普通构造函数" << endl; } // 委托构造函数,只能类内声明explicit
	Sales(const string &bn, unsigned us, double re) :bookNo(bn), units_sold(us), revenue(re) {}
	Sales(istream&);
	~Sales() {}; // 合成析构函数

	string isbn() const { return this->bookNo; } // this 类型是 const Sales *const this
	Sales& combine(const Sales&);
private:
	string bookNo;
	/*string bookNo("wz"); 不能这样初始化,只能是 = 或者｛｝*/
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
};
//******类定义 end

// 合成拷贝构造函数
Sales::Sales(const Sales &orig) :bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) { cout << "拷贝构造函数" << endl; };

// 合成拷贝赋值运算符，= 右侧的对象就是该函数的参数，运算符重载
Sales& Sales::operator=(const Sales &rhs) {
	cout << "拷贝赋值运算符" << endl;
	this->bookNo = rhs.bookNo;
	this->revenue = rhs.revenue;
	this->units_sold = rhs.units_sold;
	return *this; // 通常返回左侧对象的引用。
}

//******友元函数再次声明 start
Sales add(const Sales&, const Sales&);
ostream &print(ostream&, const Sales&);
istream &read(istream&, Sales&);
//******友元函数声明 end

Sales add(const Sales &lhs, const Sales &rhs) {
	Sales sum = lhs; // 拷贝初始化。默认情况下，拷贝类的对象其实拷贝的是对象的数据成员，要和‘赋值’区分开
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream& os, const Sales& item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

istream &read(istream& is, Sales& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales Sales& rhs) {
	units_sold += rhs.units& Sales::combine(const_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales::Sales(istream& is) {
	read(is, *this);
}

int main() {
	Sales s("wz");
	return 0;
}
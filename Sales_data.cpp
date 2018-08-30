#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct JHClass { // �ۺ���
	int a;
	double b;
	string c;
};

//******�ඨ�� start
class Sales {
	// ��Ԫ��������
	friend Sales add(const Sales&, const Sales&);
	friend ostream &print(ostream&, const Sales&);
	friend istream &read(istream&, Sales&);
public:
	Sales() = default;
	Sales(const Sales&); // �ϳɿ������캯��
	Sales& operator=(const Sales&); // �ϳɿ�����ֵ�����
	explicit Sales(const string &bn) :Sales(bn, 0, 0.0) { cout << "��ͨ���캯��" << endl; } // ί�й��캯��,ֻ����������explicit
	Sales(const string &bn, unsigned us, double re) :bookNo(bn), units_sold(us), revenue(re) {}
	Sales(istream&);
	~Sales() {}; // �ϳ���������

	string isbn() const { return this->bookNo; } // this ������ const Sales *const this
	Sales& combine(const Sales&);
private:
	string bookNo;
	/*string bookNo("wz"); ����������ʼ��,ֻ���� = ���ߣ���*/
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
};
//******�ඨ�� end

// �ϳɿ������캯��
Sales::Sales(const Sales &orig) :bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) { cout << "�������캯��" << endl; };

// �ϳɿ�����ֵ�������= �Ҳ�Ķ�����Ǹú����Ĳ��������������
Sales& Sales::operator=(const Sales &rhs) {
	cout << "������ֵ�����" << endl;
	this->bookNo = rhs.bookNo;
	this->revenue = rhs.revenue;
	this->units_sold = rhs.units_sold;
	return *this; // ͨ����������������á�
}

//******��Ԫ�����ٴ����� start
Sales add(const Sales&, const Sales&);
ostream &print(ostream&, const Sales&);
istream &read(istream&, Sales&);
//******��Ԫ�������� end

Sales add(const Sales &lhs, const Sales &rhs) {
	Sales sum = lhs; // ������ʼ����Ĭ������£�������Ķ�����ʵ�������Ƕ�������ݳ�Ա��Ҫ�͡���ֵ�����ֿ�
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
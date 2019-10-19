#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class A {
public:
    virtual void f() { cout << "A"; }
};

class B : public A {
public:
    void f() { cout << "B"; }
};

void show(A *a) {
    a->f();
}

struct lnode {
    int val;
    lnode *next;

    explicit lnode(int n = 0) : val(n), next(nullptr) {}
};

bool isMatch(string &str) {
    if (str.empty())
        return false;
    stack<char> s;

//    for (char &c:str) {
//        if (c == '(' || c == '[' || c == '{')
//            s.push(c);
//        else {
//            if (s.empty())
//                return false;
//            char temp = s.top();
//            if ((temp == '(' && c == ')') || (temp == '[' && c == ']') || (temp == '{' && c == '}'))
//                s.pop();
//            else
//                return false;
//        }
//    }

    for (string::size_type i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else {
            if (s.empty())
                return false;
            char temp = s.top();
            if ((temp == '(' && str[i] == ')') || (temp == '[' && str[i] == ']') || (temp == '{' && str[i] == '}'))
                s.pop();
            else
                return false;

//            switch (temp) {
//                case '(':
//                    if (str[i] != ')')
//                        return false;
//                    else
//                        s.pop();
//                    break;
//                case '[':
//                    if (str[i] != ']')
//                        return false;
//                    else
//                        s.pop();
//                    break;
//                case '{':
//                    if (str[i] != '}')
//                        return false;
//                    else
//                        s.pop();
//                    break;
//                default:
//                    break;
//            }
        }
    }
    return s.empty();
}

lnode *create(vector<int> &v) {
    lnode *head = nullptr, *p = head;
    for (int t:v) {
        auto *node = new lnode(t);
        if (!head) {
            p = head = node;
        } else {
            p->next = node;
            p = p->next;
        }
    }
    return head;
}

void printList(lnode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}

lnode *reverse_list(lnode *head) {
    if (!head)
        return nullptr;
    int length = 0;
    int mid;
    lnode *p = head;
    while (p) {
        ++length;
        p = p->next;
    }
    if (length == 1) {
        return head;
    } else if (length == 2) {
        p = head->next;
        head->next = nullptr;
        p->next = head;
        head = p;
    } else {
        if (length % 2 == 0)
            mid = length / 2 - 1;
        else
            mid = (length + 1) / 2 - 1;
        p = head;
        while (--mid)
            p = p->next;
        lnode *pre = nullptr, *cur = p->next, *nex = p->next->next;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            if (nex)
                nex = nex->next;
        }
        p->next = pre;
    }
    return head;
}

int main() {
//    string s1 = "([{}])";
//    cout << isMatch(s1);
//    vector<int> v = {5, 3, 8};
//    lnode *head = create(v);
//    lnode *head2 = reverse_list(head);
//    printList(head2);
    A a;
    show(&a);
    B b;
    show(&b);
    return 0;
}
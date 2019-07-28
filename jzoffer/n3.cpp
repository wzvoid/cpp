//
// Created by 王振 on 2019-07-28.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *createlist() {
    ListNode *h = nullptr, *p = nullptr;
    for (int i = 1; i <= 10; i++) {
        auto *temp = new ListNode(i);
        if (p == nullptr) {
            h = p = temp;
        } else {
            p->next = temp;
            p = p->next;
        }
    }
    return h;
}

vector<int> printListFromTailToHead(ListNode *head) {
    vector<int> v;
    if (head) {
        ListNode *front = nullptr, *current = head, *next = head->next; //前中后
        while (current) {
            current->next = front;
            front = current;
            current = next;
            if (next) //注意这边要判断
                next = next->next;
        }
        while (front) { //反转之后头结点变成fro了
            v.push_back(front->val);
            front = front->next;
        }
    }
    return v;
}

int main() {
    ListNode *h = createlist();
    vector<int> v = printListFromTailToHead(h);
    for (auto c:v)
        cout << c << " ";
    return 0;
}
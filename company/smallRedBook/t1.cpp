#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void print(ListNode *p) {
    while (p) {
        cout << p->val;
        p = p->next;
        if (p)
            cout << " ";
    }
}

ListNode *reverseK(ListNode *h, int k) {
    ListNode *front;
    ListNode *p1 = h;
    ListNode *p2 = h;

    if (!p1 || k == 1)
        return p1;
    for (int i = 1; i < k; ++i) {
        if (!p2->next)
            return h;
        p2 = p2->next;
    }
    front = p1;
    h = p2;
    while (p1->next != h) {
        p2 = p1->next;
        p1->next = p1->next->next;
        p2->next = front;
        front = p2;
    }
    p1->next = reverseK(h->next, k);
    h->next = front;

    return h;
}

int main() {
    int val;
    int c;
    ListNode *h = nullptr, *p = nullptr;
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            val = c - '0';
            auto *temp = new ListNode(val);
            if (p == nullptr) {
                h = p = temp;
            } else {
                p->next = temp;
                p = p->next;
            }
        }
    }
    int k;
    cin >> k;
    ListNode *re = reverseK(h, k);
    print(re);
}
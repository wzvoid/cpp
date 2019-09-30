#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
#include<stack>

using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
} SiListNode, *SiList;

ListNode *createlist() {
    ListNode *h = nullptr, *p = nullptr;
    for (int i = 1; i <= 9; i = i + 2) {
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

ListNode *createlist2() {
    ListNode *h = nullptr, *p = nullptr;
    for (int i = 0; i <= 9; i = i + 3) {
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

void printList(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}

ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    ListNode *p1 = pHead1, *p2 = pHead2;
    ListNode *merge = nullptr, *p3 = nullptr;
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;
    while (p1 && p2) {
        ListNode *temp = nullptr;
        if (p1->val < p2->val) {
            temp = p1;
            p1 = p1->next;
        } else {
            temp = p2;
            p2 = p2->next;
        }
        temp->next = nullptr;
        if (!merge) {
            merge = p3 = temp;
        } else {
            p3->next = temp;
            p3 = p3->next;
        }
    }
    if (p1) p3->next = p1;
    if (p2) p3->next = p2;
    return merge;
}

ListNode *ReverseList(ListNode *pHead) {
    if (!pHead)
        return nullptr;
    ListNode *pre = nullptr, *cur = pHead, *next = cur->next;
    while (cur) {
        cur->next = pre;
        pre = cur;
        cur = next;
        if (next)
            next = next->next;
    }
    return pre;
}

// 5 3 8 1
ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
    if (!pListHead)
        return nullptr;
    int count = 0;
    ListNode *p = pListHead, *q = pListHead;
    while (p != nullptr) {
        if (count < k)
            ++count;
        else
            q = q->next;
        p = p->next;
    }
    if (count < k)
        return nullptr;
    else
        return q;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *l3 = nullptr, *p3 = l3;

    while (l1 || l2) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        auto *temp = new ListNode(carry % 10);
        carry /= 10;

        if (l3 == nullptr) {
            l3 = p3 = temp;
        } else {
            p3->next = temp;
            p3 = p3->next;
        }
    }

    if (carry == 1) {
        auto *end = new ListNode(1);
        p3->next = end;
    }

    return l3;
}

int main() {
    // 1 3 5 7 9
    // 0 3 6 9
    // 0 1 3 3 5 6 7 9 9
    ListNode *a1 = createlist();
    ListNode *a2 = createlist2();
    ListNode *a3 = Merge(a1, a2);
//    print(a3);
//    cout << endl;
//    print(a2);
//    cout << endl;
//    print(a3);
    printList(a1);
    cout << endl;
    printList(a2);
    cout << endl;
    printList(addTwoNumbers(a1, a2));
    return 0;
}
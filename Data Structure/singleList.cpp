#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<stack>

using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
} SiListNode, *SiList;

ListNode *createlist() {
    ListNode *h = nullptr, *p = nullptr;
    for (int i = 1; i <= 10; i = i + 2) {
        ListNode *temp = new ListNode(i);
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
    for (int i = 0; i <= 10; i = i + 3) {
        ListNode *temp = new ListNode(i);
        if (p == nullptr) {
            h = p = temp;
        } else {
            p->next = temp;
            p = p->next;
        }
    }
    return h;
}

void print(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}

ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    ListNode *p1 = pHead1, *p2 = pHead2;
    ListNode *merge = NULL, *p3 = NULL;
    // 如果某个为空，那就返回另外一个
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;
    while (p1 && p2) {
        ListNode *temp = NULL;
        if (p1->val < p2->val) {
            temp = p1;
            p1 = p1->next;
        } else {
            temp = p2;
            p2 = p2->next;
        }
        temp->next = NULL;
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

int main() {

    return 0;
}
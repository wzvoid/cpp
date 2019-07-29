//
// Created by 王振 on 2019-07-29.
//
//重建二叉树
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int size = pre.size();
    if (size == 0)
        return nullptr;
    int c = pre[0];
    auto *p = new TreeNode(c);
    int rootIndex = 0;
    while (vin[rootIndex] != c)
        ++rootIndex;
    vector<int> pre_left, pre_right, in_left, in_right;
    for (int i = 0; i < size; ++i) {
        if (i < rootIndex) {
            in_left.push_back(vin[i]);
            pre_left.push_back(pre[i + 1]);
        } else if (i > rootIndex) {
            in_right.push_back(vin[i]);
            pre_right.push_back(pre[i]);
        }
    }
    p->left = reConstructBinaryTree(pre_left, in_left);
    p->right = reConstructBinaryTree(pre_right, in_right);
    return p;
}

int main() {

    return 0;
}
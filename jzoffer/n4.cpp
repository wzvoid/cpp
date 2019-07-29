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

//void createBiTree(TreeNode *&root) {
//    int val;
//    cin >> val;
//    if (val == 0)
//        root = nullptr;
//    else {
//        root = new TreeNode(val);
//        createBiTree(root->left);
//        createBiTree(root->right);
//    }
//}

TreeNode *createBiTree() {
    int val;
    cin >> val;
    if (val == 0)
        return nullptr;
    else {
        auto *root = new TreeNode(val);
        root->left = createBiTree();
        root->right = createBiTree();
        return root;
    }
}

void pre(TreeNode *root) {
    if (root != nullptr) {
        cout << root->val << " ";
        pre(root->left);
        pre(root->right);
    }
}

void in(TreeNode *root) {
    if (root != nullptr) {
        in(root->left);
        cout << root->val << " ";
        in(root->right);
    }
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int size = pre.size();
    if (size == 0)
        return nullptr;
    int c = pre[0];
    auto *p = new TreeNode(c);
    int rootIndex = 0;
    while (vin[rootIndex] != c)
        ++rootIndex;
    vector<int> left_pre, left_in, right_pre, right_in;
    for (int i = 0; i < size; ++i) {
        if (i < rootIndex) {
            left_pre.push_back(pre[i + 1]);
            left_in.push_back(vin[i]);
        } else if (i > rootIndex) {
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
    }
    p->left = reConstructBinaryTree(left_pre, left_in);
    p->right = reConstructBinaryTree(right_pre, right_in);
    return p;
}

int main() {
    vector<int> left = {1, 2, 4, 7, 3, 5, 6, 8}, right = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = reConstructBinaryTree(left, right);
    pre(root);
    cout << endl;
    in(root);
    return 0;
}
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<stack>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
} BiTreeNode, *BiTree;

void createBiTree(TreeNode *&root) {
    int val;
    cin >> val;
    if (val == 0)
        root = nullptr;
    else {
        root = new TreeNode(val);
        createBiTree(root->left);
        createBiTree(root->right);
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

void post(TreeNode *root) {
    if (root != nullptr) {
        post(root->left);
        post(root->right);
        cout << root->val << " ";
    }
}

vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> v;
    queue<TreeNode *> que;
    if (root) {
        que.push(root);
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            v.push_back(temp->val);
            cout << temp->val << " ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
    return v;
}

int main() {
    TreeNode *r = nullptr;
    createBiTree(r);
    PrintFromTopToBottom(r);
    return 0;
}
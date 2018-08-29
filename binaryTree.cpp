#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<stack>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int n) : val(n), left(NULL), right(NULL) {}
} BiTreeNode, *BiTree;

void createBiTree(TreeNode *&root) {
    char val;
    cin >> val;
    if (val == 0)
        root = NULL;
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

class Solution {
public:
    void push(int node) {
        while (stack2.size())
            stack1.push(stack2.top());
        stack1.push(node);
    }

    int pop() {
        while (stack1.size())
            stack2.push(stack1.top());
        return stack2.top();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    /*vector<int> a{ 5,3,1,7,8,0 }, b{ 1,3,7,5,0,8 };
    in(reConstructBinaryTree(a, b));*/
    /*TreeNode *r = NULL;
    createBiTree(r);
    pre(r);*/

    return 0;
}
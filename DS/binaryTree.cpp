#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(-1), left(nullptr), right(nullptr) {}

    explicit TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
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

//创建二叉树
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

void preOrder(TreeNode *root) {
    if (root != nullptr) {
//        if (root->left == nullptr && root->right == nullptr)
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

void levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root) {
        que.push(root);
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            cout << temp->val << " ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
}

//   9
// 3   7
//4 5 8 6

//二叉树最右边节点
TreeNode *rightNode(TreeNode *root) {
    if (root) {
        TreeNode *p = root;
        while (p->right)
            p = p->right;
        return p;
    } else {
        return nullptr;
    }
}

void path(TreeNode *p, vector<string> &v, string s) {
    if (p->left == nullptr && p->right == nullptr) {
        v.push_back(s + "");
        return;
    }
    if (p->left != nullptr) {
        path(p->left, v, s + "->" + to_string(p->left->val));
    }
    if (p->right != nullptr) {
        path(p->right, v, s + "->" + to_string(p->right->val));
    }
}

int main() {
    TreeNode *r = createBiTree();
    vector<string> v;
    string s = to_string(r->val);
    path(r, v, s);
    for (auto &c:v)
        cout << c << endl;
    return 0;
}
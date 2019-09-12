#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
#include<stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

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
    bool flag = true;
    if (root) {
        que.push(root);
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            v.push_back(temp->val);
            if (!flag) {
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            } else {
                if (temp->right)
                    que.push(temp->right);
                if (temp->left)
                    que.push(temp->left);
            }
            flag = !flag;
        }
    }
    return v;
}

//   9
// 3   7
//4 5 8 6

int main() {
    TreeNode *r = createBiTree();
    vector<int> a = PrintFromTopToBottom(r);
    for (auto c:a)
        cout << c << " ";
    return 0;
}
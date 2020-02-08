#include <iostream>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        else {
            return isS(root->left, root->right);
        }
    }

    bool isS(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        else if (left == NULL || right == NULL || left->val != right->val) {
            return false;
        }

        return isS(left->left, right->right) && isS(left->right, right->left);
    }
};
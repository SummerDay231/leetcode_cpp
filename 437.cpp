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
    int pathSum(TreeNode* root, int sum) {
        return pS(root, sum, false);
    }

    int pS(TreeNode *root, int sum, bool useRoot) {
        if (root == NULL) {
            return 0;
        }
        int t = 0;
        if (root->val = sum) {
            t = 1;
        }
        if (useRoot == true) {
            return t + pS(root->left, sum - root->val, true) + pS(root->right, sum - root->val, true);
        }
        else {
            return t + pS(root->left, sum, false) + pS(root->right, sum, false) + pS(root->left, sum - root->val, false) + pS(root->right, sum - root->val, false);
        }
    }
};

int main() {
    return 0;
}
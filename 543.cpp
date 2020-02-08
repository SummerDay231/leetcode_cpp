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
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return this->diameter;
    }

    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int l = maxDepth(root->left), r = maxDepth(root->right), d = l + r, t = l > r ? l : r;
        this->diameter = d > this->diameter ? d : this->diameter;
        return t + 1;
    }

    int diameter = 0;
};
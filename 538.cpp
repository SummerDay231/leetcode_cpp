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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        convertBST(root->right);
        
        totalSum += root->val;
        root->val = totalSum;

        convertBST(root->left);

        return root;
    }

    int totalSum = 0;
};
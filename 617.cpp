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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // merge root
        TreeNode *newT;
        if (t1 != NULL && t2 != NULL) {
            newT = new TreeNode(t1->val + t2->val);
            newT->left = mergeTrees(t1->left, t2->left);
            newT->right = mergeTrees(t1->right, t2->right);
        }
        else if (t2 == NULL) {
            newT = t1;
        }
        else {
            newT = t2;
        }

        return newT;
    }
};

int main() {
    return 0;
}
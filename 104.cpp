#include <iostream>
#include <stack>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        TreeNode *temp;
        int d, maxD = 0;
        stack<TreeNode*> nodes;
        stack<int> depths;
        nodes.push(root);
        depths.push(1);
        while (!nodes.empty()) {
            temp = nodes.top();
            nodes.pop();
            d = depths.top();
            depths.pop();
            maxD = d > maxD ? d : maxD;
            if (temp->left != NULL) {
                nodes.push(temp->left);
                depths.push(d+1);
            }
            if (temp->right != NULL) {
                nodes.push(temp->right);
                depths.push(d+1);
            }
        }
        return maxD;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        else {
            int d1 = maxDepth(root->left), d2 = maxDepth(root->right), d3 = d1 > d2 ? d1 : d2;
            return d3 + 1;
        }
    }
};
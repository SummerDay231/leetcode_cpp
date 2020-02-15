#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> levels;
        if (root == NULL) {
            return levels;
        }
        vector<int> *thisLevel = new vector<int>;
        int n = 0, levelNum = 1, nextLevelNum = 0;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *temp = nodes.front();
            thisLevel->push_back(temp->val);
            nodes.pop();
            n++;
            if (temp->left != NULL) {
                nodes.push(temp->left);
                nextLevelNum++;
            }
            if (temp->right != NULL) {
                nodes.push(temp->right);
                nextLevelNum++;
            }
            if (n == levelNum) {
                n = 0;
                levelNum = nextLevelNum;
                nextLevelNum = 0;
                levels.push_back(*thisLevel);
                delete thisLevel;
                thisLevel = new vector<int>;
            }
        }
        return levels;
    }
};
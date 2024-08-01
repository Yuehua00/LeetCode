// Promblem : https://leetcode.com/problems/evaluate-boolean-binary-tree/?source=submission-noac
// 將 bool binary tree 算出結果
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        bool newval;
        if(root->val == 2) newval = left || right;
        if(root->val == 3) newval = left && right;
        return newval;
    }
};

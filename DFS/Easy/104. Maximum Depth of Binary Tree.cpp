// Problem : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?source=submission-noac
// find the max depth of tree

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
    int d = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else {
            int lef = maxDepth(root->left);
            int rig = maxDepth(root->right);
            d = max(lef, rig) + 1;
        }
        return d;
    }
};

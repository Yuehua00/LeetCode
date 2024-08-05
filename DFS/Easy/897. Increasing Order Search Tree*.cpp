// problem : https://leetcode.com/problems/increasing-order-search-tree/description/
// 參考 : https://leetcode.com/problems/increasing-order-search-tree/solutions/1957287/c-simple-solution-with-visual-explanation/
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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* left = increasingBST(root->left);
        TreeNode* right = increasingBST(root->right);

        root->left = nullptr;
        root->right = right;

        if(!left) return root;
        TreeNode* tmp = left;
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        tmp->right= root;

        return left;
    }
};

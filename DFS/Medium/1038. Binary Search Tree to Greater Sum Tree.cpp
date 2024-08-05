// Problem : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
// Same Problem : https://leetcode.com/problems/convert-bst-to-greater-tree/description/
// 參考 : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/solutions/5364556/beats-100-explained-with-video-c-java-python-js-reverse-inorder-traversal-easy/
// 將每個節點加上比他大的數字

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
    int tmp = 0;

    void solve(TreeNode* root){
        if(root == NULL) return;
        solve(root->right);
        tmp += root->val;
        root->val = tmp;
        solve(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};

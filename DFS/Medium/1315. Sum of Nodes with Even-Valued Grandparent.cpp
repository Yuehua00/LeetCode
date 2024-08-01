// Problem : https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
// 祖父母節點為偶數的孫子節點合

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
    int ans = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return ans;

        if(root->val % 2 == 0){
            if(root->left != NULL && root->left->left != NULL)ans += root->left->left->val;   // if 當中的條件相反會造成子孫節點先被訪問，可能訪問到不存在區域(因為沒先確認父節點)
            if(root->left != NULL && root->left->right != NULL)ans += root->left->right->val;
            if(root->right != NULL && root->right->left != NULL)ans += root->right->left->val;
            if(root->right != NULL && root->right->right != NULL)ans += root->right->right->val;
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);

        return ans;
    }
};

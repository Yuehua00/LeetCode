// Problem : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// 參考 : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/editorial/
// 求多少子樹的總和等於父節點的合

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

    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if(root->val == sum/count){
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

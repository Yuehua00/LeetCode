// Problem : https://leetcode.com/problems/deepest-leaves-sum/description/
// 參考 : https://leetcode.com/problems/deepest-leaves-sum/solutions/3941981/c-simple-recursive-code-one-pass-solution-with-comments/
// 最深子節點合

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
    void traverse(TreeNode* root, int curlevel, int &maxlevel, int &ans){
        if(root == NULL) return;
        if(curlevel == maxlevel) ans += root->val;
        else if(curlevel > maxlevel){
            ans = root->val;
            maxlevel = curlevel;
        }

        traverse(root->left, curlevel+1, maxlevel, ans);  // +1 改成 ++ 會 WA，原因是 ++ 會先做完 traverse 再 ++
        traverse(root->right, curlevel+1, maxlevel, ans);

    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0, maxlevel = 0;
        traverse(root, 0, maxlevel, ans);
        return ans;
    }
};

// Problem : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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

    void traversal(TreeNode* root, vector<int> &p){
        if(root == NULL) return;
        traversal(root->left, p);
        p.emplace_back(root->val);
        traversal(root->right, p);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};

// stack 來源 : https://leetcode.com/problems/binary-tree-inorder-traversal/editorial/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (curr != NULL || !stack.empty()) {
            while (curr != NULL) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};
*/

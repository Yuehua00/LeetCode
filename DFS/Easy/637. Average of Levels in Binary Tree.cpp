

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
    long long int arr[10000+10];
    double cnt[10000+10];
    vector<double> ans;
    int max_deep = 0;

    void compute_node(TreeNode* root, int deep){
        if(root == NULL) return;
        arr[deep] += root->val;
        cnt[deep]++;
        max_deep = max(max_deep, deep+1);
        compute_node(root->left, deep+1);
        compute_node(root->right, deep+1);
        return;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        ans.clear();
        compute_node(root, 0);
        for(int i = 0; i < max_deep; i++){
            if(cnt[i] > 1) ans.emplace_back(arr[i] / cnt[i]);
            else ans.emplace_back(arr[i]);
        }
        return ans;
    }
};

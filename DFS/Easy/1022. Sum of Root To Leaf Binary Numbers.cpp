// Problem : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
// 將樹上列成二進制，求總和
// 參考 : https://leetcode.com/problems/number-of-enclaves/solutions/3388131/python-java-c-simple-solution-easy-to-understand/

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
    int ans = 0, tar = 0;
    int cul_BinToDec(int s){
        int i = 0, re = 0, tmp = 0;
        while(s > 0){
            tmp = s % 10;
            s /= 10;
            re += tmp * pow(2, i);
            i++;
        }
        return re;
    }

    int traversalAndCul(TreeNode* root){
        if(root == NULL){
            ans += cul_BinToDec(tar);
            tar = 0;
        }      
        return ans;
    }

    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val * 2 + root->val);
        if(root->left == NULL && root->right == NULL) return val;
        else return sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};

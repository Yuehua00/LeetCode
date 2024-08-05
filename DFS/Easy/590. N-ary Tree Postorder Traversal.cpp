// Problem : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
// 參考 : https://leetcode.com/problems/n-ary-tree-postorder-traversal/solutions/1567050/c-easy-to-understand-recursive-solution/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void traverse(Node* root, vector<int> &p){
        if(root == NULL) return;
        for(auto i : root->children){
            traverse(i, p);
        }
        p.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;

    }
};

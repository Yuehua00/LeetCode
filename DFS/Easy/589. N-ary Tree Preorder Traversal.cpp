// Problem : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// inorder 順序輸出

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

    void traversal(Node* root, vector<int>& p){
        if(root == NULL) return;
        p.emplace_back(root->val);
        for(auto i : root->children){
            traversal(i, p);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};

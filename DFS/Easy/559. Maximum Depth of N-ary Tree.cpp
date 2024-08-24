// Problem : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// 求最深幾層 (類似 104)

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
    int maxDepth(Node* root) {
        int d = 0;
        if(root == NULL) return 0;
        else {
            d = 0;
            for(auto i : root->children){
                d = max(maxDepth(i), d);
            }
        }
        return d+1;
    }
};

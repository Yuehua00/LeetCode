// problem : https://leetcode.com/problems/counting-bits/description/
// 求每個二進制有幾個 1
// 參考 : https://leetcode.com/problems/counting-bits/solutions/79527/four-lines-c-time-o-n-space-o-n/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i&(i-1)] + 1;  // 因為 i 相比 i & (i-1) 多了一個 "1"
        }

        return ans;
    }
};

// Problem : https://leetcode.com/problems/divisor-game/description/
// 參考 : https://leetcode.com/problems/divisor-game/solutions/274608/simple-dp-java-solution/
// 參考 : https://leetcode.com/problems/divisor-game/solutions/274606/java-c-python-return-n-2-0/

class Solution {
public:
    bool divisorGame(int n) {
        int dp[1000+5];
        dp[0] = dp[1] = false;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0 && !dp[i-j]){   // 能找到一個 j 整除 i && 在 i-j 的情況下必輸
                    dp[i] = true;    // 這樣就必勝
                }
            }
        }

        return dp[n];
    }
};

/*
          return N % 2 == 0;
*/

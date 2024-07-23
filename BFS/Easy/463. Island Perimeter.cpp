// https://leetcode.com/problems/island-perimeter/
// 求土地邊長

class Solution {
public:
    int ans = 0;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    int c = 4;
                    for(int k = 0; k < 4; k++){
                        int a = i + dir[k][0];
                        int b = j + dir[k][1];
                        if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b]){
                            c--;
                        }
                    }
                    ans += c;
                }
            }
        }
        return ans;
    }
};

// Problem : https://leetcode.com/problems/flood-fill/description/
// 將指定位置的上下左右填充成新的顏色
// 參考 : https://leetcode.com/problems/flood-fill/solutions/1590584/c-simple-dfs-97-6-faster-91-6-better-memory-use/

class Solution {
public:

    void DFS(vector<vector<int>>& image, int val, int i, int j, int newColor){
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val){
            return;
        }
        image[i][j] = newColor;
        DFS(image, val, i+1, j, newColor);
        DFS(image, val, i-1, j, newColor);
        DFS(image, val, i, j+1, newColor);
        DFS(image, val, i, j-1, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        DFS(image, val, sr, sc, color);
        return image;
    }
};

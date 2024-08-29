// Problem : https://leetcode.com/problems/pascals-triangle/description/
// 參考 : https://leetcode.com/problems/pascals-triangle/solutions/4016203/three-approaches-beginner-friendly-full-explanation-c-java-python/

// Method 1: Using Recursion-------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};

        vector<vector<int>> previous = generate(numRows-1);
        vector<int> newRows(numRows, 1);

        for(int i = 1; i < numRows-1; i++){
            newRows[i] = previous.back()[i-1] + previous.back()[i];
        }
        previous.emplace_back(newRows);
        return previous;
    }
};
// Method 2: Using Combinatorial Formula---------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        if(numRows == 0) return {};
        ans.emplace_back(vector<int>{1});
        if(numRows == 1) return ans;
         
        int cnt = 0, tmp = 0;
        while(cnt++ < numRows-1){
            vector<int> tmp_vec;
            tmp_vec.emplace_back(1);
            for(int i = 1; i < cnt; i++){
                tmp = ans.back()[i-1] + ans.back()[i];
                tmp_vec.emplace_back(tmp);
            }
            tmp_vec.emplace_back(1);
            ans.emplace_back(tmp_vec);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
*/

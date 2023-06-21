class Solution {
public:

    int helpTab(vector<vector<int>> &grid){
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int a = 200, b = 200;
                    if(i>0)
                        a = dp[i-1][j];
                    if(j>0)
                        b = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(a,b);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        return helpTab(grid);
    }
};
class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool *flag, int r, int c, int row , int col){
        if (r < 0 || c < 0 || r >= row || c >= col) return;
        if (grid2[r][c] == 0) return;
        if (grid2[r][c] == 1 && grid1[r][c] != 1) *flag = false;
        grid2[r][c] = 0;
        dfs(grid1, grid2, flag, r + 1, c, row, col);
        dfs(grid1, grid2, flag, r, c + 1, row, col);
        dfs(grid1, grid2, flag, r - 1, c, row, col);
        dfs(grid1, grid2, flag, r, c - 1, row, col);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size();
        int col = grid2[0].size();
        int count = 0;
        bool f = true;
        bool *flag = &f;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid2[i][j] == 1) {
                    dfs(grid1, grid2, flag, i, j, row, col);
                    if(*flag == true) {
                        count++;
                    }
                }
                *flag = true;
            }
        }
        return count;
    }
};

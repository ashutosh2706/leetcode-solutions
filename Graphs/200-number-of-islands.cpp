class Solution {
    private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x >= grid.size() || x < 0) return;
        if(y >= grid[x].size() || y < 0) return;

        if(grid[x][y] == '1') {
            grid[x][y] = '0';
            dfs(grid, x+1, y);
            dfs(grid, x-1, y);
            dfs(grid, x, y+1);
            dfs(grid, x, y-1);
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0; i<grid.size(); i++) 
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        return islands;
    }
};
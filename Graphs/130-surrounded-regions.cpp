class Solution {
private:
bool dfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &vis) {

    if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size()) return 0;

    if(grid[x][y] == 'X') return 1;

    bool b = 1;
    if(!vis[x][y]) {
    vis[x][y] = 1;
    b = dfs(x+1, y, grid, vis) && b;
    b = dfs(x-1, y, grid, vis) && b;
    b = dfs(x, y+1, grid, vis) && b;
    b = dfs(x, y-1, grid, vis) && b;
    }
    return b;
}


void fill(int x, int y, vector<vector<char>> &grid) {
    if(grid[x][y] == 'O') {
        grid[x][y] = 'X';
        fill(x+1, y, grid);
        fill(x-1, y, grid);
        fill(x, y+1, grid);
        fill(x, y-1, grid);
    } 
}

public:
    void solve(vector<vector<char>>& grid) {
    vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));

    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(!vis[i][j] && grid[i][j] == 'O')
                if(dfs(i,j,grid,vis)) fill(i,j,grid);
        }
    }
    
    }
};
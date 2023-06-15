class Solution {
private:
int dfs(int x, int y, vector<vector<int>> &grid) {
    if(x == grid.size() || y == grid[0].size() || x < 0 || y < 0) return 0;
    if(grid[x][y] == 1) return 1;

    grid[x][y] = 1;

    bool left = dfs(x,y-1,grid);
    bool right = dfs(x,y+1,grid);
    bool up = dfs(x-1,y,grid);
    bool down = dfs(x+1,y,grid);
    return left && right && up && down;

}
public:
    int closedIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for(int i=0; i<grid.size(); i++) 
    for(int j=0; j<grid[0].size(); j++) 
    if(grid[i][j] == 0) ans+=dfs(i,j,grid);
    return ans;       
    }
};
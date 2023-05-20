class Solution {
private:
    int f(vector<vector<int>> &grid, int x, int y, int &r, int &c) {
        if(x == r || y == c) return 0;
        if(x<0 || y<0) return 0;
        if(grid[x][y] == 1) {
            grid[x][y]=0;
            return 1 + f(grid, x+1, y,r,c) + f(grid, x-1, y,r,c) + f(grid, x, y+1,r,c) + f(grid, x , y-1,r,c);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) ans = max(ans, f(grid, i, j,n,m));
            }
        }
        return ans;
    }
};
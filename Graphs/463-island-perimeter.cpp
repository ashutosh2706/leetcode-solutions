class Solution {
private:
int peri = 0;
void dfs(int x, int y, set<pair<int,int>> &vis, vector<vector<int>> &grid) {
    if(x == grid.size() or x < 0 or y == grid[x].size() or y < 0 || grid[x][y] == 0) {
        peri++;
        return;
    }
    vis.insert({x,y});
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &p:dirs) {
        if(vis.count({x+p.first, y+p.second}) == 0)
            dfs(x+p.first,y+p.second,vis,grid);
    }
}

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        set<pair<int, int>> vis;
        for(int i=0,b=1; i<grid.size() and b; i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,vis,grid);
                    b=0;
                    break;
                }
            }
        }
        return peri;
    }
};
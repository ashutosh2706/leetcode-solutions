class Solution {
private:
void dfs(int x, int y, vector<vector<int>> &grid, set<pair<int,int>> &vis) {
    if(vis.count({x,y})) return;

    vis.insert({x,y});
    
    if(x+1<grid.size() and grid[x+1][y] >= grid[x][y]) dfs(x+1,y,grid,vis);
    if(x-1>=0 and grid[x-1][y]>=grid[x][y]) dfs(x-1,y,grid,vis);
    if(y+1<grid[0].size() and grid[x][y+1] >= grid[x][y]) dfs(x,y+1,grid,vis);
    if(y-1>=0 and grid[x][y-1]>=grid[x][y]) dfs(x,y-1,grid,vis);

}
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        set<pair<int,int>> at,pa;
        vector<vector<int>> res;
        for(int j=0; j<grid[0].size(); j++) {
            dfs(0,j,grid,pa);
            dfs(grid.size()-1,j,grid,at);        
        }
        for(int i=0; i<grid.size(); i++) {
            dfs(i,0,grid,pa);
            dfs(i,grid[0].size()-1,grid,at);
        }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(at.count({i,j}) and pa.count({i,j})) res.push_back({i,j});
            }
        }
        return res;
    }
};
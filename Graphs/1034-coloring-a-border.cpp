class Solution {
private:
int color, curr;
int dfs(int x, int y, vector<vector<int>> &grid, set<pair<int,int>> &vis) {
    if(x==grid.size() or x<0 or y==grid[x].size() or y<0 or grid[x][y] != curr) return 1;
    vis.insert({x,y});
    vector<pair<int,int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &p:dirs) {
        if(vis.count({x+p.first, y+p.second}) == 0) {
            if(dfs(x+p.first, y+p.second, grid, vis)) 
                grid[x][y] = color;
        }
    }
    return 0;
}
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        set<pair<int,int>> vis;
        this->color = color;
        this->curr = grid[row][col];
        dfs(row, col, grid, vis);
        return grid;
    }
};
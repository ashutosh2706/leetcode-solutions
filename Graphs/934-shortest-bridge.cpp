class Solution {
private:
void dfs(int x, int y, vector<vector<int>> &grid, set<pair<int,int>> &vis) {
    if(x<0 or x==grid.size() or y<0 or y==grid.size() or grid[x][y]==2) return;
    if(grid[x][y] == 0) {
        vis.insert({x,y});
        return;
    }
    grid[x][y]=2;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &p:dirs) {
        dfs(x+p.first, y+p.second, grid, vis);
    } 
}
public:
    int shortestBridge(vector<vector<int>>& grid) {
         
    int n = grid.size();
    bool b =1;
    set<pair<int,int>> vis;
    for(int i=0; i<n and b; i++) {
        for(int j=0; j<n; j++)
            if(grid[i][j]) {
                dfs(i,j,grid, vis);
                b=0;
                break;
            }
    }
    queue<vector<int>> q;
    for(auto &it : vis)
        q.push({it.first, it.second, 0});
    
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {

            int i = q.front()[0], j = q.front()[1], val = q.front()[2];
            q.pop();
            if(grid[i][j] == 1) return val;
            if(grid[i][j] == 0) {
                grid[i][j] = 2;
                if(i+1 < grid.size()) q.push({i+1, j, val+1});
                if(i-1 > 0) q.push({i-1, j, val+1});
                if(j+1 < grid.size()) q.push({i,j+1,val+1});
                if(j-1 > 0) q.push({i,j-1,val+1});
            } 
        }
        
    }
    return 0;
    }
};
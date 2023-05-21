class Solution {
private:
pair<int,int> BFS(int i, int j, vector<vector<int>> &grid) {

    pair<int, int> p = {i,j};
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int x = q.front().first, y = q.front().second; q.pop();
            p = max(p, {x,y});
            if(x+1 < grid.size() and grid[x+1][y]) {
                q.push({x+1,y});
                grid[x+1][y] = 0;
            }
            if(x-1>=0 and grid[x-1][y]) {
                q.push({x-1,y});
                grid[x-1][y] = 0;
            }
            if(y+1 < grid[0].size() and grid[x][y+1]) {
                q.push({x,y+1});
                grid[x][y+1] = 0;
            }
            if(y-1>=0 and grid[x][y-1]) {
                q.push({x,y-1});
                grid[x][y-1] = 0;
            }
        }
    }
    return p;
}
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> res;
        int m = land.size(), n = land[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(land[i][j]) {
                    auto p = BFS(i,j,land);
                    res.push_back({i,j,p.first,p.second});
                }
            }
        }
        return res;
    }
};
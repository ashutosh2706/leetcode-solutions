class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int fresh = 0, mins = -1;
    int r = grid.size(), c = grid[0].size();
    for(int i=0; i<r; i++) 
        for(int j=0; j<c; j++) {
            if(grid[i][j] == 2) q.push({i,j});
            else if(grid[i][j] == 1) fresh++;
        }
    if(fresh == 0) return 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto p = q.front();
            q.pop();
            int x = p.first, y=p.second;
            if(x+1 < r && grid[x+1][y] == 1) { grid[x+1][y]=2; q.push({x+1,y}); }
            if(x-1 >= 0 && grid[x-1][y]==1) { grid[x-1][y] = 2; q.push({x-1,y}); }
            if(y+1 < c && grid[x][y+1]==1) { grid[x][y+1] = 2; q.push({x,y+1}); }
            if(y-1 >= 0 && grid[x][y-1]==1) { grid[x][y-1] = 2; q.push({x,y-1}); }
        }
        mins++;
    }
    for(auto a:grid) for(int i:a) if(i==1) return -1;
    return mins;
    }
};
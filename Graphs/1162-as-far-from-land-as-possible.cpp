class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) q.push({i,j});
            }
        }

        int ans = INT_MIN;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front().first, y = q.front().second; q.pop();
                ans = max(ans, grid[x][y]-1);
                if(x+1<n and grid[x+1][y] == 0) {
                    q.push({x+1,y});
                    grid[x+1][y] = 1+grid[x][y];
                }
                if(x-1>=0 and grid[x-1][y] == 0) {
                    q.push({x-1,y});
                    grid[x-1][y] = 1+grid[x][y];
                }
                if(y+1<n and grid[x][y+1] == 0) {
                    q.push({x,y+1});
                    grid[x][y+1] = 1+grid[x][y];
                }
                if(y-1>=0 and grid[x][y-1] == 0) {
                    q.push({x,y-1});
                    grid[x][y-1] = 1+grid[x][y];
                }
            }
        }
        if(ans == INT_MIN or ans == 0) return -1;
        return ans;
    }
};
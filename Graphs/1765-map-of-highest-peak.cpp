class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    q.push({i,j});
                }
                else grid[i][j] = -1;
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x+1 < grid.size() and grid[x+1][y] == -1) {
                    grid[x+1][y] = 1+grid[x][y];
                    q.push({x+1,y});
                }
                if(x-1>=0 and grid[x-1][y] == -1) {
                    grid[x-1][y] = 1+grid[x][y];
                    q.push({x-1,y});
                }
                if(y+1<grid[0].size() and grid[x][y+1]==-1) {
                    grid[x][y+1] = 1+grid[x][y];
                    q.push({x,y+1});
                }
                if(y-1>=0 and grid[x][y-1] == -1) {
                    grid[x][y-1] = 1 + grid[x][y];
                    q.push({x,y-1});
                }
            }
        }
        return grid;
    }
};
class Solution {
private:
    bool possible(int& R, int& C, vector<vector<int>>& cells, int lim) {

        int grid[R][C];
        memset(grid,0,sizeof(grid));
        queue<pair<int,int>> q;
        for(int x=0; x<=lim; x++)  {
            grid[cells[x][0]-1][cells[x][1]-1] = 1;
        }

        // multi-sourced BFS
        for(int x=0; x<C; x++) {
            if(!grid[0][x]) {
                q.push({0,x});
                grid[0][x]=1;
            }
        }

        vector<vector<int>> dirs {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int nx = q.front().first, ny = q.front().second;
                q.pop();
                if(nx == R-1) return 1;
                for(auto& dir : dirs) {
                    if(nx + dir[0] >= 0 and nx + dir[0] < R and ny + dir[1] >= 0 and ny + dir[1] < C and grid[nx+dir[0]][ny+dir[1]] == 0) {
                        q.push({nx+dir[0],ny+dir[1]});
                        grid[nx+dir[0]][ny+dir[1]] = 1;
                    } 
                }
            }
        }

        return 0;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0, hi = cells.size()-1, mid;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(possible(row, col, cells, mid)) 
                lo = mid+1;
            else 
                hi = mid-1;
        }
        return lo;
    }
};
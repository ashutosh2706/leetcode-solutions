class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
    int n = grid.size(), ans = 0;
    if(grid[0][0] || grid[n-1][n-1]) return -1;

    auto valid = [](int x, int y, vector<vector<int>> &grid) {

        int n = grid.size();
        if(x == n || y == n || x < 0 || y < 0 || grid[x][y]) return 0;
        return 1;
        
    };

    vector<vector<int>> dirs {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,1}, {-1,-1}, {1,-1}, {1,1}};
    
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()) {
        int sz = q.size();
        while(sz--)  {

            int x = q.front().first, y = q.front().second; 
            q.pop();
            if(x == n-1 && y == n-1) return ans+1;
            for(auto &dir:dirs) {

                if(valid(x + dir[0], y + dir[1], grid)) {
                    q.push({x + dir[0], y + dir[1]});
                    grid[x+dir[0]][y+dir[1]] = 1;
                }
            }
        }
        ans++;
    }

    return -1;
    }
};
class Solution {
private:
    int solve(set<pair<int,int>> &set, vector<vector<int>> &grid) {
        int ans = INT_MAX;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] == 0) {
                    for(auto &p : set) {
                        if(grid[p.first][p.second] > 1) {
                            
                            grid[p.first][p.second] -= 1;
                            grid[i][j] = 1;
                            ans = min(ans, abs(i-p.first) + abs(j-p.second) + solve(set, grid));
                            grid[i][j] = 0;
                            grid[p.first][p.second] += 1;
                            
                        }    
                        
                    }
                }
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
        
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        set<pair<int,int>> set;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] > 1) set.insert({i,j});
                
            }
        }
        
        return solve(set, grid);
        
    }
};
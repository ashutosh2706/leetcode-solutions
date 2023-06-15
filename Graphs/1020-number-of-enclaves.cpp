class Solution {
private:
int cnt = 0;
int DFS(int i, int j, vector<vector<int>> &grid) {
    if(i < 0 or i == grid.size() or j < 0 or j == grid[0].size()) return 0;
    if(grid[i][j] == 0) return 1;
    cnt++;
    grid[i][j] = 0;
    bool b = 1;
    vector<pair<int,int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &dir:dirs) {
        b = DFS(i+dir.first, j+dir.second, grid) and b;
    }
    return b;
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cnt = 0;
                if(grid[i][j] and DFS(i,j,grid)) ans += cnt;
            }
        }  
        return ans;
    }
};
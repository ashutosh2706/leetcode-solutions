class Solution {
private:
int BFS(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int b = 1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int i=q.front().first, j=q.front().second; q.pop();
            if(b and grid1[i][j] == 0) b=0;
            if(i+1<grid2.size() and grid2[i+1][j]) {
                q.push({i+1,j});
                grid2[i+1][j] = 0;
            }
            if(i-1>=0 and grid2[i-1][j]) {
                q.push({i-1,j});
                grid2[i-1][j] = 0;
            }
            if(j+1<grid2[0].size() and grid2[i][j+1]) {
                q.push({i,j+1});
                grid2[i][j+1] = 0;
            }
            if(j-1>=0 and grid2[i][j-1]) {
                q.push({i,j-1});
                grid2[i][j-1] = 0;
            }
        }
    }
    return b;
}
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid2.size(), n = grid2[0].size(), ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j]) {
                    if(BFS(i,j,grid1,grid2)) ans++;
                }
            }
        }
        return ans;
    }
};
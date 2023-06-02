class Solution {
private:
bool isValid(pair<int,int> &p, int x, int y, int n) {
    return (p.first+x >= n or p.first+x < 0 or p.second+y >=n or p.second+y < 0) ? 0 : 1;
}
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        dist[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({dist[0][0],0,0});
        while(!pq.empty()) {

            int ht = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            for(auto &p : dirs) {
                if(!isValid(p,x,y,n)) continue;
                if(grid[x+p.first][y+p.second] <= ht) {
                    if(dist[x+p.first][y+p.second] > ht) {
                        dist[x+p.first][y+p.second] = ht;
                        pq.push({ht,x+p.first,y+p.second});
                    }
                } else {
                    if(dist[x+p.first][y+p.second] >= grid[x+p.first][y+p.second]) {
                        dist[x+p.first][y+p.second] = grid[x+p.first][y+p.second];
                        pq.push({dist[x+p.first][y+p.second], x+p.first, y+p.second});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
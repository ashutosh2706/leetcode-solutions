class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

    int r = heights.size(), c = heights[0].size();
    vector<vector<int>> dist(r, vector<int>(c,1e9));
    dist[0][0] = 0;
    vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({dist[0][0],0,0});
    while(!pq.empty()) {

        int dis = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
        pq.pop();
        for(auto &dir : dirs) {
            if(dir.first+x >= 0 and dir.first+x < r and dir.second+y >= 0 and dir.second+y < c) {

                int m = heights[x+dir.first][y+dir.second], n = heights[x][y];
                if(abs(m-n) <= dis) {

                    if(dist[x+dir.first][y+dir.second] > dis) {
                        dist[x+dir.first][y+dir.second] = dis;
                        pq.push({dis, x+dir.first, y+dir.second});
                    }
                } else {
                    if(dist[x+dir.first][y+dir.second] > abs(m-n)) {
                        dist[x+dir.first][y+dir.second] = abs(m-n);
                        pq.push({abs(m-n), x+dir.first, y+dir.second});
                    }
                }

            }

        }
    }
    return dist[r-1][c-1];
        
    }
};
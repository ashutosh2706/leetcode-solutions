class Solution {
private:
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /* Prim's MST */
        unordered_map<int, vector<pair<int,int>>> graph;
        for(int i=0; i<points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(y2-y1) + abs(x2-x1);
                graph[i].push_back({j,dist});
                graph[j].push_back({i, dist});
            }
        }
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;      // {wt,point}
        unordered_set<int> vis;
        pq.push({0, 0});      // start from first point
        int sum = 0;
        while(!pq.empty()) {
            int wt = pq.top().first, point = pq.top().second;
            pq.pop();
            if(vis.count(point)) continue;
            vis.insert(point);
            sum += wt;
            for(int j=0; j<points.size(); j++) {
                if(!vis.count(j)) {
                    int dist = abs(points[point][0] - points[j][0]) + abs(points[point][1] - points[j][1]);
                    pq.push({dist,j});

                }
            }
        }
        return sum;
    }
};
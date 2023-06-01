class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /* dijkstra Algorithm
        *  As the paths are directed, no need to create bi-directional edges
        */

        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>{});
        for(int i=0; i<times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});   //{node, time}
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    // {time, node}
        pq.push({0, k});
        while(!pq.empty()) {

            int node = pq.top().second, dis = pq.top().first;
            pq.pop();
            for(auto &p : graph[node]) {
                if(dis + p.second < dist[p.first]) {
                    dist[p.first] = dis + p.second;
                    pq.push({dist[p.first], p.first});
                }
            }
        }

        int mini = 0;
        for(int i=1; i<dist.size(); i++) 
            mini = max(mini, dist[i]);
        return mini == 1e9 ? -1 : mini;
   }
};
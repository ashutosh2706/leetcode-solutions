class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>{});
    for(int i=0; i<flights.size(); i++) 
        graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    queue<vector<int>> q;
    vector<int> dist(n,1e9);
    dist[src]=0;
    q.push({0,src,0}); // {stops, node, distance}
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        int stop = v[0], node = v[1], dis = v[2];
        if(stop > k) continue;
        for(auto &adj : graph[node]) {
            if(dis + adj.second < dist[adj.first]) {
                dist[adj.first] = dis + adj.second;
                q.push({stop+1, adj.first, dist[adj.first]});
            }
        }
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];

    }
};
class Solution {
int mod = (int)(1e9+7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>{});
    for(int i=0; i<roads.size(); i++) {
        graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<long long> dist(n, 1e12), ways(n);
    ways[0] = 1, dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()) {
        long long dis = pq.top().first, node = pq.top().second;
        pq.pop();
        for(auto &p : graph[node]) {
            if(dis + p.second < dist[p.first]) {
                ways[p.first] = ways[node]; 
                dist[p.first] = dis + p.second;
                pq.push({dist[p.first], p.first});
            } else if(dis + p.second == dist[p.first]) 
                ways[p.first] = (ways[p.first] + ways[node]) % mod;
        }
    }    
    return ways[n-1] % mod;
    }
};
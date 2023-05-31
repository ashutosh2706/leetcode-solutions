class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        
    vector<vector<pair<int,double>>> graph(n, vector<pair<int,double>>{});
    for(int i=0; i<edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], succ[i]});
        graph[edges[i][1]].push_back({edges[i][0], succ[i]});
    }
    vector<double> dist(n,0.0);
    dist[start] = 1.0;
    priority_queue<pair<double,int>> pq;
    pq.push({1.0, start});
    while(!pq.empty()) {
        int node = pq.top().second;
        double dis = pq.top().first;
        pq.pop();
        for(auto &p : graph[node]) {
            double d = pow(10, log10(dis) + log10(p.second));
            if(d > dist[p.first]) {
                dist[p.first] = d;
                pq.push({d, p.first});
            }

        }
    }
    return dist[end];
    }
};
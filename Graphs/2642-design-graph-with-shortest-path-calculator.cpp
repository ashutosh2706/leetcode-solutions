class Graph {
public:
    unordered_map<int, vector<pair<int,int>>> adj;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto &v : edges) {
            adj[v[0]].push_back({v[1],v[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v=edge[1], cost=edge[2];
        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int n1, int n2) {
        vector<int> dist(N, 1e9);
        dist[n1] = 0;
        pq.push({0, n1});
        while(!pq.empty()) {
            auto d = pq.top().first, node = pq.top().second;
            pq.pop();

            for(auto &p : adj[node]) {
                
                if(d + p.second < dist[p.first]) {
                    dist[p.first] = d+p.second;
                    pq.push({d+p.second, p.first});
                }
                
            }
        }
        return dist[n2] == 1e9 ? -1 : dist[n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
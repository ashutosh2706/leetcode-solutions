class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> graph(n, vector<int>{});
        vector<int> indeg(n), cost(n);
        for(auto &v:relations) {
            graph[v[0]-1].push_back(v[1]-1);
            indeg[v[1]-1]++;
        }
        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(indeg[i] == 0) {
                q.push(i);
                cost[i] = time[i];
            }
        }
        while(!q.empty()) {
            auto tp = q.front();
            q.pop();

            for(auto &adj : graph[tp]) {
                cost[adj] = max(cost[adj], cost[tp] + time[adj]);
                if(--indeg[adj] == 0) {
                    q.push(adj);
                }
            }
        }
        return *max_element(begin(cost), end(cost));
    }
};
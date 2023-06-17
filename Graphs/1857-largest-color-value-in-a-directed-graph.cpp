class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // cycle in directed graph can be found out using kahn's algorithm

        int n = colors.length(), nodes = 0;
        vector<int> indeg(n);
        vector<vector<int>> graph;
        graph.resize(n);
        queue<int> q;
        for(int i=0; i<edges.size(); i++) {
            indeg[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>> col(n, vector<int>(26));
        for(int i=0; i<n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
                col[i][colors[i]-'a']++;
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                nodes++;
                int node = q.front(); q.pop();
                ans = max(ans, col[node][colors[node] - 'a']);
                for(auto& adj:graph[node]) {
                    for(int i=0; i<26; i++) {
                        col[adj][i] = max(col[adj][i], col[node][i]);
                        if(colors[adj] - 'a' == i) {
                            col[adj][i] = max(col[adj][i], col[node][i] + 1);
                        }
                    }
                    if(--indeg[adj] == 0) q.push(adj);
                }

            }
        }
        if(nodes < n) return -1;
        return ans;
    }
};
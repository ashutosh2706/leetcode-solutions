class Solution {
private:
    double dfs(string node, string end, unordered_map<string, vector<pair<string,double>>> &adj, set<string> &vis) {
        if(adj.find(node) == adj.end()) return 0.0;
        if(node == end) return 1;
        vis.insert(node);
        double ans = 0.0;
        for(auto &p : adj[node]) {
            if(vis.count(p.first) == 0) {
                ans = max(ans, p.second * dfs(p.first, end, adj, vis));
            }
        }
        return ans;
    } 

public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i=0; i<values.size(); i++) {
            adj[eq[i][0]].push_back({eq[i][1], values[i]});
            adj[eq[i][1]].push_back({eq[i][0], (double)(1/values[i])});
        }
        set<string> vis;
        vector<double> res;
        for(int i=0; i<queries.size(); i++) {
            vis.clear();
            double out = dfs(queries[i][0], queries[i][1], adj, vis);
            out == 0.0 ? res.push_back(-1.0) : res.push_back(out);
        }
        return res; 
    }
};
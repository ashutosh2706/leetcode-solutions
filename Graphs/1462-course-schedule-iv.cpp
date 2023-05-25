class Solution {
private:
set<int> dfs(int node, vector<vector<int>>& graph, map<int, set<int>> &map) {
    if(map.count(node)) return map[node];
    set<int> set;
    for(auto &adj:graph[node]) {
        auto ret = dfs(adj, graph, map);
        for(auto &i:ret) {
            set.insert(i);
        }
    }
    set.insert(node);
    map[node] = set;
    return set;
}
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
 
    vector<vector<int>> graph(n);
    for(int i=0; i<pre.size(); i++) {
        graph[pre[i][0]].push_back(pre[i][1]);
    }
    map<int, set<int>> map;
    for(int i=0; i<n; i++) {
        if(map.count(i) == 0) 
            dfs(i, graph, map);
    }
    vector<bool> ans;
    for(int i=0; i<queries.size(); i++) {
        int s = queries[i][0], e = queries[i][1];
        map[s].count(e)==1 ? ans.push_back(1) : ans.push_back(0);
    }
    return ans;
    }
};
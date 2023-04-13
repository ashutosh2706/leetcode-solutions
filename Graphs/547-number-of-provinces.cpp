class Solution {

private:
void dfs(int node, vector<vector<int>> &graph, vector<int> &vis) {

    vis[node] = 1;
    for(int i=0; i<graph.size(); i++) {
        if(i == node) continue;
        if(graph[node][i] && !vis[i]) dfs(i, graph, vis);
    }
}

public:
    int findCircleNum(vector<vector<int>>& graph) {
    
    vector<int> vis(graph.size());
    int province = 0;

    for(int i=0; i<graph.size(); i++) {
        if(!vis[i]) {
            dfs(i, graph, vis);
            province++;
        }
    }

    return province;
    }
};
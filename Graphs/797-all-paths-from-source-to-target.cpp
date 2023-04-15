class Solution {
private:
vector<vector<int>> ans;
void dfs(int node, vector<vector<int>> &graph, vector<int> &stk) {
    if(node == graph.size() - 1) {
        ans.push_back(stk);
        return;
    }
    for(auto &nodes : graph[node]) {
        stk.push_back(nodes);
        dfs(nodes, graph, stk);
        stk.pop_back();
    }
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> st;
        st.push_back(0);
        dfs(0, graph, st);
        return ans;
    }
};
class Solution {
private:
    bool bip = true;
    void f(int node, vector<vector<int>>& graph, int col, vector<int>& color) {
        if(!bip) return;
        color[node] = col;
        for(int adj:graph[node]) {
            if(color[adj] == -1) {
                f(adj, graph, !col, color);
            }else if(color[adj] == col) {
                bip=false;
                return;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(), -1);
        for(int i=0; i<graph.size(); i++) {
            if(col[i] == -1 && bip) {
                f(i, graph, 0, col);
            }
        }
        return bip;
    }
};
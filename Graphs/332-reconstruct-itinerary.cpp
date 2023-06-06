/*
*   'Use all the tickets once and only once'
*   Each ticket represents an edge, and each edge should be used only once...
*   This  =>  find a eulerian circuit starting from "JFK".
*
*   Hierholzer's Algorithm for printing eulerian circuit
*/
class Solution {
private:
void dfs(string node, unordered_map<string,priority_queue<string, vector<string>, greater<string>>>& graph,vector<string> &res) {
    if(graph.find(node) == graph.end() or graph[node].empty()) {
        res.push_back(node);
        return;
    }
    while(!graph[node].empty()) {
        auto adj = graph[node].top();
        graph[node].pop();
        dfs(adj,graph,res);
    } 
    res.push_back(node);
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(int i=0; i<tickets.size(); i++) {
            graph[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> res;
        dfs("JFK",graph,res);
        reverse(begin(res),end(res));
        return res;
    }
};
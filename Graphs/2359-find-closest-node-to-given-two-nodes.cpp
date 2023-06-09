class Solution {
private:
void dfs(int node, int dist, vector<int>& edges, unordered_map<int, int> &vis) {
    vis[node] = dist;
    if(edges[node] != -1 and vis.count(edges[node]) == 0) {
        dfs(edges[node], dist+1, edges, vis);
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int n1, int n2) {
        unordered_map<int,int> m1,m2;
        dfs(n1,0,edges,m1);
        dfs(n2,0,edges,m2);
        int node = edges.size(), dist = edges.size();
        for(auto &p : m1) {
            if(m2.find(p.first) != m2.end()) {
                int maxi = max(p.second, m2[p.first]);
                if(maxi < dist) {
                    dist = maxi;
                    node = p.first;
                } else if(maxi == dist) node = min(node, p.first);
            }
        }
        return node == edges.size() ? -1 : node;
    }
};
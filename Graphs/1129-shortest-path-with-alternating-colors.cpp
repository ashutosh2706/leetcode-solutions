class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {

        vector<int> res(n, -1);
        vector<vector<int>> g_red(n, vector<int>{}), g_blue(n, vector<int>{});
        for(auto &edge:red) g_red[edge[0]].push_back(edge[1]);  // directed edge
        for(auto &edge : blue) g_blue[edge[0]].push_back(edge[1]);
        set<int> rvis, bvis;
        int dist = 0;
        queue<pair<int,int>> q;     // {node, col}
        q.push({0,0});
        q.push({0,1});
        rvis.insert(0);
        bvis.insert(0);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front().first, col = q.front().second; q.pop();
                if(res[node] == -1) res[node] = dist;
                if(col) {
                    for(auto &adj : g_blue[node]) {
                        if(bvis.count(adj) == 0) {
                            q.push({adj, !col});
                            bvis.insert(adj);
                        }
                    }
                } else {
                    for(auto &adj : g_red[node]) {
                        if(rvis.count(adj) == 0) {
                            q.push({adj, !col});
                            rvis.insert(adj);
                        }
                    }
                }
            }
            dist++;
        }
        return res;
    }
};
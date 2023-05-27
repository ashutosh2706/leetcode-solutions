class DSU {
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int nodes) {
        for(int i=0; i<nodes; i++) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int findPar(int node) {
        if(parent[node]==node) return node;
        return parent[node]=findPar(parent[node]); 
    }

    void Union(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(rank[u] < rank[v]) parent[u] = v;
        else if(rank[u] > rank[v]) parent[v] = u;
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {

        int n = acc.size();
        DSU dsu(n);
        unordered_map<string,int> map;
        for(int i=0; i<n; i++) {
            for(int j=1; j<acc[i].size(); j++) {
                string str = acc[i][j];
                if(map.count(str)) dsu.Union(map[str], i);
                else map[str] = i;
            }
        }
        vector<set<string>> vec(n, set<string>{});
        for(int i=0; i<n; i++) {
            for(int j=1; j<acc[i].size(); j++) {
                int par = dsu.findPar(map[acc[i][j]]);
                vec[par].insert(acc[i][j]);
            }
        }
        vector<vector<string>> res;
        for(int i=0; i<n; i++) {
            vector<string> v;
            if(vec[i].empty()) continue;
            v.push_back(acc[i][0]);
            for(auto &ss:vec[i]) v.push_back(ss);
            res.push_back(v);
        }
        return res;    
    }
};
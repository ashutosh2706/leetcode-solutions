class DSU {
public:
    int find(int n, vector<int> &par) {

        int p = par[n];
        while(p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    int unionn(int n1, int n2, vector<int> &par, vector<int> &rank) {

        int p1 = find(n1, par), p2 = find(n2, par);
        if(p1 == p2) return 0;
        if(rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return 1;
    }

};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1, 1);
        for(int i=1; i<=n; i++) par[i] = i;

        DSU obj;
        for(auto &p : edges) {
            if(!obj.unionn(p[0], p[1], par, rank)) return { p[0], p[1] };
        }
        return {};
    }
};
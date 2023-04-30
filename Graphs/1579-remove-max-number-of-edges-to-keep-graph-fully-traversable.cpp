class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {

        parent.resize(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        rank.resize(n+1);
        components = n;
    }

    int Find(int n) {

        if(n == parent[n]) return n;
        return parent[n] = Find(parent[n]);
    }

    void Union(int n1, int n2) {

        int p1 = Find(n1), p2 = Find(n2);
        if(p1 == p2) return;

        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else if(rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
        components--;
    }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU alice(n);
        DSU bob(n);

        sort(begin(edges), end(edges), [](vector<int> v1, vector<int> v2) {
            return v1[0] > v2[0];
        });

        int edgesCnt = 0;

        for(auto &vec: edges) {

            int t = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(t == 3) {

                bool edgeAdded = 0;

                if(alice.Find(u) != alice.Find(v)) {
                    edgeAdded = 1;
                    alice.Union(u, v);
                }
                if(bob.Find(u) != bob.Find(v)) {
                    edgeAdded = 1;
                    bob.Union(u, v);
                }

                if(edgeAdded) edgesCnt++;
            } else if(t == 2) {
                if(bob.Find(u) != bob.Find(v)) {
                    edgesCnt++;
                    bob.Union(u, v);
                }            

            } else {

                if(alice.Find(u) != alice.Find(v)) {
                    edgesCnt++;
                    alice.Union(u, v);
                }
            }

        }

        if(alice.components == 1 && bob.components == 1) {
            return edges.size() - edgesCnt;
        }
        return -1;
        
    }
};
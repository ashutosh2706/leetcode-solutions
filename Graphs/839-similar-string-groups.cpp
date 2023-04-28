class Solution {
private:
public:
    int numSimilarGroups(vector<string>& strs) {
        
        unordered_map<int, vector<int>> adj;
        int n = strs.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(convertible(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                DFS(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
    
private:

    int convertible(string &s1, string &s2) {
        int c = 0;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) c++;
        }
        return c == 0 || c == 2;
    }


    void DFS(int u, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {

        vis[u] = 1;
        for(auto &v : adj[u]) {
            if(!vis[v]) DFS(v, adj, vis);
        }
    }
};
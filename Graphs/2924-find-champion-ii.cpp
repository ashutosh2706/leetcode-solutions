class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for(auto &v : edges) indeg[v[1]]++;
        int cnt = 0, node;
        for(int i=0; i<n; ++i) {
            if(indeg[i] == 0) {
                cnt++;
                node = i;
            } 
        }
        return cnt == 1 ? node : -1;
        
    }
};
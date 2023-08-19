class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    
    unordered_map<int,vector<int>> map;
    for(auto &v:paths) {
        map[v[0]].emplace_back(v[1]);
        map[v[1]].emplace_back(v[0]);
    }
    vector<int> res(n);
    for(int i=1; i<=n; ++i) {

        set<int> plants{1,2,3,4};
        vector<int> adj = map[i];
        for(auto &a : adj) {
            if(res[a-1]) {
                plants.erase(res[a-1]);
            }
        }
        res[i-1] = *begin(plants);
    }
    return res;
    }
};
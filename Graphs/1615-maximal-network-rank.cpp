class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    unordered_map<int, set<int>> map;
    for(auto &v : roads) {
        map[v[0]].insert(v[1]);
        map[v[1]].insert(v[0]);

    }
    int res = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            int ans = 0;
            if(map[j].count(i)) ans -= 1;
            res = max(res, ans  + (int)map[i].size() + (int)map[j].size());
        }   
    }
    return res;
    }
};
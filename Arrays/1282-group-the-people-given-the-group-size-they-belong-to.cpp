class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        map<int, vector<int>> map;
        for(int i=0; i<groupSizes.size(); i++) {
            int e = groupSizes[i];
            if(map[e].size() == e) {
                res.emplace_back(map[e]);
                map.erase(e);
            }
            map[e].emplace_back(i);
        }
        for(auto &[a,v] : map) res.emplace_back(v);
        return res;

    }
};
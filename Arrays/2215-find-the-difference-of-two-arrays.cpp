class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> S1, S2;
        for(auto &i : nums1) S1.insert(i);
        for(auto &i : nums2) S2.insert(i);
        vector<vector<int>> res(2, vector<int>{});
        for(auto &i:S1) {
            if(S2.count(i) == 0) res[0].push_back(i);
        }
        for(auto &i:S2) {
            if(S1.count(i) == 0) res[1].push_back(i);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); ++i) {
            map[nums[i]]=i;
        }
        for(auto &v : operations) {
            int ind = map[v[0]];
            map.erase(v[0]);
            map[v[1]]=ind;
        }
        vector<int> v(nums.size());
        for(auto &p : map) {
            v[p.second] = p.first;
        }
        return v;
    }
};
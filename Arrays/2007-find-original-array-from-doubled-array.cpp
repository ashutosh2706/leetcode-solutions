class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        if(n&1) return vector<int>{};
        sort(begin(nums), end(nums));
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i) {
            if(mp.find(nums[i]) == mp.end()) {
                res.push_back(nums[i]);
                mp[2*nums[i]]++;
            } else {
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
            }

        }
        return mp.empty() ? res : vector<int>{};
    }
};

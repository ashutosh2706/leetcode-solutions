class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {   
    int l = 0;
    set<int> S;
    for(int r = 0; r < nums.size(); r++) {

        if(S.count(nums[r])) return 1;
        else S.insert(nums[r]);
        if(r-l == k) S.erase(nums[l++]);
    }
    return 0;
    }
};
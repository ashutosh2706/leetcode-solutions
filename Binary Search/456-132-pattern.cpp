class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    int mini = nums[0];
    map<int,int> mp;
    for(auto &i : nums) mp[i]++;
    if(--mp[nums.front()] == 0) mp.erase(nums.front());
    for(int i=1; i<nums.size()-1; i++) {
        if(--mp[nums[i]] == 0) mp.erase(nums[i]);

        auto it = mp.upper_bound(mini);
        if(it != mp.end()) {
            if(it->first > mini and nums[i] > it->first) {
                return 1;
            }
        }   
        mini = min(mini, nums[i]);

    }
    return 0;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) { 
    if(nums.size() < 3) return 0;
    map<int,int> map;
    for(int i=1; i<nums.size(); i++) {
        map[nums[i]]++;
    }
    int mini = nums.front(), maxi;
    for(int i=1; i<nums.size()-1; i++) {
        if(--map[nums[i]] == 0) map.erase(nums[i]);
        maxi = prev(end(map))->first;
        if(nums[i] > mini and nums[i] < maxi) {
            return 1;
        }
        mini = min(mini, nums[i]);
    }
    return 0;
    }
};   

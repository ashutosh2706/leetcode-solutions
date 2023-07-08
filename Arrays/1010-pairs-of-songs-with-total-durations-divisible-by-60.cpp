class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
    sort(begin(nums),end(nums));
    int ans = 0;
    map<int,int> map;
    map[nums[0]]++;
    for(int i=1; i<nums.size(); i++) {
        int mul = (nums[i]/60)+1;
        while((60*mul - nums[i]) <= nums[i-1]) {
            int r = (60*mul) - nums[i];
            ans += map[r];
            mul++;
        }
        map[nums[i]]++;
    }
    return ans;
    }
};
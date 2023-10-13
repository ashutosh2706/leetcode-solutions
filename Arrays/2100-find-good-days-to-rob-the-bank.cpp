class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        vector<int> res, left(nums.size()), right(nums.size());
        left[0] = right.back() = 0;
        int cnt = 0;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] <= nums[i-1]) left[i] = ++cnt;
            else cnt = 0;

        }
        cnt = 0;
        for(int i=nums.size()-2; i>=0; --i) {
            if(nums[i] <= nums[i+1]) right[i] = ++cnt;
            else cnt = 0;
        }
        for(int i=0; i<nums.size(); ++i) {  
            if(left[i] >= time and right[i] >= time) res.push_back(i);
        }

        return res;
    }
};
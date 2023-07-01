class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(s.count(nums[i])) {
                res.push_back(nums[i]);
            } else s.insert(nums[i]);
        }
        for(int i=1; i<=nums.size(); i++) 
            if(s.count(i) == 0) {
                res.push_back(i);
                break;
            }
        return res;
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        
    vector<int> res;
    vector<int> dp;
    for(auto &i : nums) {
        auto it = upper_bound(begin(dp), end(dp), i) - dp.begin();
        if(it == dp.size()) dp.push_back(i);
        else dp[it] = i;
        res.push_back(it+1);
    }
    return res;      
        
    }
};
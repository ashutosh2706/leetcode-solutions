class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        stack<int> s;
        vector<int> res(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            while(!s.empty() && nums[i] >= nums[s.top()]) s.pop();
            if(!s.empty()) res[i] = s.top() - i;
            s.push(i); 
        }
        return res;
    }
};
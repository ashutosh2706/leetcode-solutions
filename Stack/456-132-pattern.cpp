class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
    int curmin = nums.front();
    stack<pair<int, int>> S;
    S.push({nums[0], curmin});
    for(int i=1; i<nums.size(); i++) {

        while(!S.empty() && S.top().first <= nums[i]) S.pop();
        if(!S.empty() && (S.top().first > nums[i] && nums[i] > S.top().second)) return 1;
        else S.push({nums[i], curmin});
        curmin = min(curmin, nums[i]);
    }

    return 0;
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
    stack<int> S;
    int n = nums.size();
    for(int i= n-2; i>=0; i--) {
        while(!S.empty() and S.top() <= nums[i]) S.pop();
        S.push(nums[i]);
    }
    vector<int> res(n);
    for(int i=n-1; i>=0; i--) {

        while(!S.empty() and nums[i] >= S.top()) S.pop();
        if(S.empty()) {
            S.push(nums[i]);
            res[i] = -1;
        }else {
            res[i] = S.top();
            S.push(nums[i]);
        }
    }
    return res;
    }
};
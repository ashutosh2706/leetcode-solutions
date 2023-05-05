class Solution {
public:
    int findMin(vector<int>& nums) {
        // rotation pivot
    int start = 0, end = nums.size()-1, mid, ans = INT_MAX;
    while(start <= end) {
        mid = start + (end-start)/2;
        ans = min(ans, nums[mid]);
        if((nums[end] > nums[mid] && nums[start] < nums[mid]) || nums[start] > nums[mid]) end = mid-1;
        else start = mid+1;
    }
    
    return ans;
    }
};
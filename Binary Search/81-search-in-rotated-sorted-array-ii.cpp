class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int lo=0, hi=nums.size()-1,mid;
    while(lo <= hi) {
        mid = lo+(hi-lo)/2;
        if(nums[mid] == target) return 1;
        if(nums[lo] == nums[mid] and nums[mid] == nums[hi]) {
            lo++;
            hi--;
            continue;
        }
        if(nums[lo] == nums[mid]) lo=mid+1;
        else if(nums[hi] == nums[mid]) hi=mid-1;
        else {
            if(nums[lo] < nums[mid]) {
                if(target >= nums[lo] and target < nums[mid]) hi=mid-1;
                else lo = mid+1; 
            }
            if(nums[mid] < nums[hi]) {
                if(target > nums[mid] and target <= nums[hi]) lo = mid+1;
                else hi=mid-1; 
            }
        }
    }
    return 0;
    }
};
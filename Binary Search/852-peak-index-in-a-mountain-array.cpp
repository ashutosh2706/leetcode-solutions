class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {   
    int n = nums.size();
    int lo = 0, hi = n-1,mid;
    while(lo<=hi) {
        mid=lo+(hi-lo)/2;
        if(mid > 0 and mid < n-1) {
            if(nums[mid-1] < nums[mid] and nums[mid] > nums[mid+1]) return mid;
            nums[mid+1] > nums[mid] ? lo = mid+1 : hi=mid-1;
        }else if(mid==0) {
            if(nums[mid+1] < nums[mid]) return mid;
            nums[mid+1] > nums[mid] ? lo=mid+1 : hi=mid-1;
        } else {
            if(nums[mid] > nums[mid-1]) return mid;
            nums[mid-1]>nums[mid] ? hi=mid-1 : lo=mid+1;
        }
    }
    return -1;
    }
};
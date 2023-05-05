class Solution {
    private:
    int pivot(vector<int> nums) {
    int lo = 0, hi = nums.size() - 1, mid = -1;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(mid > 0 && mid < nums.size() - 1) {
            if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) return mid;
        }
        if(nums[mid] <= nums[hi]) hi = mid - 1;
        else lo = mid + 1;
    }
    return mid;
}
public:
    int search(vector<int>& nums, int target) {
        int piv = pivot(nums);
    if(nums[piv] == target) return piv;
    if(piv == 0) {
        int lo = 0, hi = nums.size() - 1, mid = -1;
        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return nums[mid] == target ? mid : -1;
    }else {

        if(target <= nums[piv - 1] && nums[0] <= target) {
        int lo = 0, hi = piv - 1, mid = -1;
        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return nums[mid] == target ? mid : -1;
        }else if(target <= nums[nums.size() - 1] && nums[piv] <= target ) {
        int lo = piv, hi = nums.size() - 1, mid = -1;
        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return nums[mid] == target ? mid : -1;
        }
    }

    return -1;
    }
};
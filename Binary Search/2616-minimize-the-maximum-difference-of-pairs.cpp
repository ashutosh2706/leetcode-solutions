class Solution {
public:
    bool found(int& mid, vector<int> &nums, int &p) {
        int cnt = 0;
        for(int i=0; i<nums.size();) {
            if(i < nums.size()-1 and (nums[i+1] - nums[i]) <= mid) {
                cnt++;
                i+=2;
            }
            else i++;
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));
        int lo = 0, hi = nums.back()-nums.front(), mid;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            found(mid, nums, p) ? hi = mid-1 : lo = mid+1;
        }
        return lo;
    }
};
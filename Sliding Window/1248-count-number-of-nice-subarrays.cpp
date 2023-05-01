class Solution {
private:
int getAtMost(vector<int> &nums, int k) {

    int ans = 0;
    int l = 0, od = 0;
    for(int r=0; r<nums.size(); r++) {
        if(nums[r] % 2 == 1) od++;
        while(l <= r && od > k) {
            if(nums[l] % 2 == 1) od--;
            l++;
        }
        ans += (r-l+1);       
    }
    return ans;
}
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return getAtMost(nums, k) - getAtMost(nums, k-1);
    }
};
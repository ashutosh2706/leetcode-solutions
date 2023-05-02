class Solution {
private:
int getAtMost(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    int l = 0, cnt = 0, ans = 0;
    for(int r=0; r<nums.size(); r++) {
        if(map[nums[r]] == 0) cnt++;
        map[nums[r]]++;
        if(cnt <= k) ans += (r-l+1);
        else {
            while(cnt > k) {
                map[nums[l]]--;
                if(map[nums[l]] == 0) cnt--;
                l++;
            }
            ans += r-l+1;
        }
    }
    return ans;
}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getAtMost(nums, k) - getAtMost(nums, k-1);
    }
};
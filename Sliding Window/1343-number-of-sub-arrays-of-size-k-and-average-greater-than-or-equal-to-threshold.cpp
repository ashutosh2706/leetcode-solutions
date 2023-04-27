class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int thres) {
    
    if(nums.size() < k) return 0; 
    int l = 0, r = k-1, cnt = 0;
    thres *= k;
    long long sum = 0;
    for(int i=0; i<=r; i++) sum += nums[i];
    while(1) {
        if(sum >= thres) cnt++;
        r++;
        if(r == nums.size()) break;
        sum -= nums[l++];
        sum += nums[r];
    }
    return cnt;

    }
};
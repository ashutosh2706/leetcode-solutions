class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        map[0]=1;
        int n = nums.size();
        int sum = 0, cnt = 0;
        for(int i=0; i<n; ++i) {
            sum += nums[i] & 1;
            cnt += map[sum-k];
            map[sum]++;
        }
        return cnt;
    }
};
class Solution {
public:
    typedef long long int ll;
    int minimumAddedCoins(vector<int>& nums, int target) {
        
        sort(begin(nums), end(nums));
        ll sum = 0, cnt = 0;
        for(int i=0; i<nums.size();) {
            if(sum >= target) return cnt;
            if(nums[i] > (sum+1)) {
                ++cnt;
                sum = 2*sum + 1;
            } else {
                while(i < nums.size() and nums[i] <= (sum+1)) 
                    sum += nums[i++];
            }
        }	
        
        while(sum < target) {
            ++cnt;
            sum = 2*sum+1;
        }
        return cnt;
    }
};

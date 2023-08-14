class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {

        int n = nums.size();
        sort(begin(nums), end(nums));
        typedef long long int ll;
        ll sum = ((ll)k*((ll)k+1))/2;
        int start = 1, end = k;
        for(int i=0; i<n; ++i) {
            while(i > 0 and nums[i-1] == nums[i]) {
                i++;
                if(i == n) break;
            }
            if(i < n and nums[i] <= end) {
                sum -= nums[i];
                sum += (++end);
            }
        }
        return sum;
    }
};
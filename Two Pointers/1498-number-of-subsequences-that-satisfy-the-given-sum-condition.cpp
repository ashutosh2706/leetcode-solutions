class Solution {
const unsigned int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        
    sort(begin(nums), end(nums));
    int n = nums.size(), i = 0, j = n - 1, cnt = 0;
    int P[n+1];
    P[0] = 1;

    for(int i=1; i<=n; i++) 		// Precompute power of 2
	P[i] = (2 * P[i-1]) % mod;


    while(i < nums.size() && (2*nums[i] <= target)) {
        while(j >= i && (nums[i] + nums[j] > target)) j--;
        cnt = (cnt + P[j-i]) % mod;
        i++;
    }

    return cnt;

    }
};
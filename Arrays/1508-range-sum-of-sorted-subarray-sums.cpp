class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int N, int L, int R) {
    vector<long> v;
    for(int i=0; i<N; i++) {
        long sum = nums[i];
        v.push_back(sum);
        for(int j=i+1; j<N; j++) {
            sum += nums[j];
            v.push_back(sum);
        }
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=L-1; i<R; i++) {
        ans = (ans + v[i]) % mod;
    }
    return ans % mod;
    
    }
};
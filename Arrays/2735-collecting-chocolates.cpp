class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int> cnums(begin(nums), end(nums));
        for(auto &e:nums) cnums.push_back(e);
        int n = nums.size();
        long long ans = LLONG_MAX;
        vector<int> val(n, 1e9);
        for(int rot=0; rot<n; rot++) {
            long long sum = 0;
            for(int i=0; i<n; i++) {
                if(val[i] > cnums[i+rot]) val[i] = cnums[i+rot];
                sum += val[i];
            }
            sum += (long long)rot * (long long)x;
            ans = min(ans, sum);
        }
        return ans;
    }
};
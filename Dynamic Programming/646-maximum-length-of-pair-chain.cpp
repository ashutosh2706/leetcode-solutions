class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    sort(begin(pairs), end(pairs), [](vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
    });
    int n = pairs.size();
    auto disjoint = [](vector<int>&a, vector<int>&b) {
        return b[0] > a[1];
    };
    vector<int> dp(n+1, 1);
    for(int j=n-1; j>=0; j--) {
        for(int i=n-1; i>j; i--) {
            if(disjoint(pairs[j], pairs[i])) {
                dp[j] = max(dp[j], 1 + dp[i]);
            }
        }
    }
    return dp[0];
    }
};
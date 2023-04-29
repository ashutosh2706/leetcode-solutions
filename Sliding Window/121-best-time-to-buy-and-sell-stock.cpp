class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // sliding window
        int l = 0, ans = 0;
        for(int r = 0; r < prices.size(); r++) {

            if(prices[r] < prices[l]) l = r;
            else ans = max(ans, prices[r] - prices[l]);
        }
        return ans;
    }
};
class Solution {
public:
    int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& i:nums) pq.push(i);
        while(k > 0) {
            int x = pq.top(); pq.pop();
            pq.push(x+1);
            k--;
        }

        long long prod = 1;
        while(!pq.empty()) {
            prod = (prod * pq.top()) % mod;
            pq.pop();
        }
        return prod % mod;
    }
};
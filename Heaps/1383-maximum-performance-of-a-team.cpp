class Solution {
const unsigned int mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(begin(v), end(v), greater<pair<int,int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long ans = 0, sum = 0;
        for(int i=0; i<n; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
            if((int)pq.size()>k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, v[i].first * sum);
        }
        return ans % mod;
    }
};
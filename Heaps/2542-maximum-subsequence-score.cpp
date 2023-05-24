class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }
        sort(begin(vp), end(vp), greater<pair<int,int>>());
        long long sum = 0, ans = 0;
        for(int i=0; i<n; i++) {
            pq.push(vp[i].second);
            sum += vp[i].second;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = max(ans, vp[i].first * sum);
        }
        return ans;
    }
};
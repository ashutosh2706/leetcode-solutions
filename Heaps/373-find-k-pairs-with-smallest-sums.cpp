class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(pq.size() < k) {
                    pq.push({nums1[i] + nums2[j], {i,j}});
                    continue;
                }
                if(pq.top().first > (nums1[i] + nums2[j])) {
                    pq.pop();
                    pq.push({nums1[i] + nums2[j], {i,j}});
                } else break;
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            auto p = pq.top().second;
            res.push_back(vector<int>{nums1[p.first], nums2[p.second]});
            pq.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

    priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto a:mpp) {
        pq.push({a.second, a.first});
        if(pq.size() > k) pq.pop();
    }

    vector<int> ans;
    while(pq.size() > 0) { ans.push_back(pq.top().second); pq.pop(); }
    return ans;
    }
};
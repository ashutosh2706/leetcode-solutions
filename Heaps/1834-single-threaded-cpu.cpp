class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& nums) {
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> et, pt;
    int n = nums.size();
    for(int i=0; i<n; i++)
        et.push({nums[i][0], i});
    long long current = et.top().first;
    vector<int> res;
    while(!et.empty() or !pt.empty()) {
        if(!et.empty() and et.top().first > current) 
            current = et.top().first;

        while(!et.empty() and (et.top().first <= current)) {
            int ind = et.top().second;
            et.pop();
            pt.push({nums[ind][1], ind});
        }
        if(!pt.empty()) {
            auto p = pt.top(); pt.pop();
            res.push_back(p.second);
            current += p.first;
        }
    }
    return res;

    }
};
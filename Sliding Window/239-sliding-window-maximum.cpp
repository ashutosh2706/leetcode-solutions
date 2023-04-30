class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        unordered_map<int, int> map;
        int l = 0, r = 0;
        priority_queue<int> pq;
        vector<int> res;
        for(; r<k; r++) {
            pq.push(nums[r]);
            map[nums[r]]++;
        }
        res.push_back(pq.top());
        while(r < nums.size()) {
            pq.push(nums[r]);
            map[nums[r++]]++;
            map[nums[l++]]--;
            while(map[pq.top()] <= 0) pq.pop();
            res.push_back(pq.top()); 
        }
        return res;
    }
};
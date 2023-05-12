class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < nums.size(); i++) pq.push(nums[i]);
        int i = 1;
        while(i < k) { pq.pop(); i++; } 
        return pq.top();
    }
};
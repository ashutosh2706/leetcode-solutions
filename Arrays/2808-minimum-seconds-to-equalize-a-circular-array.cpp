class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        int minTime = INT_MAX;
        for(auto &[a, v] : map) {
            int cnt = ceil(((double)v.front() + (double)(n-1-v.back()))/(double)2);
            for(int i=0; i<v.size()-1; i++) {
                cnt = max(cnt, (int)(v[i+1]-v[i])/2);
            }
            minTime = min(minTime, cnt);
        }
        return minTime;
    }
};
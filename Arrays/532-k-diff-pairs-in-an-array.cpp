class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size(), ans = 0;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++) map[nums[i]]++;
        for(int i=0; i<n;) {
            int e = nums[i];
            map[e]--;
            if(map[e+k]) ans++;
            while(i < n and nums[i]==e) i++;
        }
        return ans;
    }
};
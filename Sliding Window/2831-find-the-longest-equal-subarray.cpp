class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        vector<vector<int>> vec(nums.size()+1, vector<int>{});
        for(int i=0; i<nums.size(); ++i) {
            vec[nums[i]].emplace_back(i);
        }

        int ans = 0;
        for(auto &v : vec) {
            int cnt = 0;
            for(int l=0,r=0; r<v.size(); r++) {
                if(r > 0) cnt += (v[r] - v[r-1] - 1);
                while(cnt > k) {
                    cnt -= (v[l+1] - v[l] - 1);
                    l++;
                }
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
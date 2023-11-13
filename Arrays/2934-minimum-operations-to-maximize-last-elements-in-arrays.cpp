class Solution {
public:
    int solve(vector<int> &c, vector<int> &r) {
        int n = c.size();
        int cnt = 0;
        for(int i=0; i<n-1; ++i) {
            if(c[i] > c[n-1] or r[i] > r[n-1]) {
                if(r[i] > c[n-1] or c[i] > r[n-1]) return 1e9; 
                cnt ++;
            }
        }
        return cnt;
        
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans = solve(nums1, nums2);
        swap(nums1.back(), nums2.back());
        ans = min(ans, 1 + solve(nums1, nums2));
        return ans == 1e9 ? -1 : ans;
    }
};
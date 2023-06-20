class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> res(N,-1);
        long long int sum = 0;
        int l = 0, r = 0, ind = k;
        for(int r = 0, l = 0, ind = k; r < N; r++) {
            sum += nums[r];
            if(r-l == 2*k) {
                res[ind++] = sum/(2*k+1);
                sum -= nums[l++];
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void perm(int ind, vector<int> &nums, int mask, vector<int> res) {
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(int i=ind; i<nums.size(); i++) {
            if((mask & (1 << i)) == 0) {
                res.push_back(nums[i]);
                perm(0, nums, mask | (1<<i), res);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        perm(0,nums,0,{});
        return ans;
    }
};
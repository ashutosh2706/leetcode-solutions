class Solution {
private:
    void fun(vector<vector<int>>& ds, int ind, vector<int> nums) {
        if(ind==nums.size()) {
            ds.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++) {
            swap(nums[i], nums[ind]);
            fun(ds, ind+1, nums);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> s;
        fun(s,0,nums);
        return s;
    }
};
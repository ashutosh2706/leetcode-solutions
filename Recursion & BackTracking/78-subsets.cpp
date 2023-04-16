class Solution {
private:
vector<vector<int>> subset;

void backTrack(int ind, vector<int> &nums, vector<int> &v) {
    if(ind == nums.size()) {
        subset.push_back(v);
        return;
    }

    v.push_back(nums[ind]);
    backTrack(ind+1, nums, v);
    v.pop_back();
    backTrack(ind+1, nums, v);
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        backTrack(0, nums, v);
        return subset;
    }
};
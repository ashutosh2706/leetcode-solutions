class Solution {
private:
set<vector<int>> subset;

void backTrack(int ind, vector<int> &nums, vector<int> v) {
    if(ind == nums.size()) {
        sort(begin(v), end(v));
        subset.insert(v);
        return;
    }

    v.push_back(nums[ind]);
    backTrack(ind+1, nums, v);
    v.pop_back();
    backTrack(ind+1, nums, v);
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        backTrack(0, nums, v);
        return vector<vector<int>>(begin(subset), end(subset));
        
    }
};
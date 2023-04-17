class Solution {
private:

set<vector<int>> ans;

void func(int ind, vector<int> &nums, int target, vector<int> v) {
    if(target == 0) {
        ans.insert(v);
        return;
    }
    for(int i=ind; i<nums.size(); i++) {
        if(i > ind && nums[i] == nums[i-1]) continue;
        if(nums[i] > target) break;
        v.push_back(nums[i]);
        func(i+1, nums, target - nums[i], v);
        v.pop_back();
    }
}


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
    sort(begin(candidates), end(candidates));
    func(0, candidates, target, {});

    return vector<vector<int>>(begin(ans), end(ans));
    }
};
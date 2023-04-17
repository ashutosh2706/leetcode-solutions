class Solution {
private:

set<vector<int>> ans;

void func(int ind, vector<int> &nums, int target, vector<int> v) {
    if(target == 0) ans.insert(v);
    if(ind == nums.size() || nums[ind] > target) return;
    v.push_back(nums[ind]);
    func(ind, nums, target-nums[ind], v);
    func(ind+1, nums, target-nums[ind], v);
    v.pop_back();
    func(ind+1, nums, target, v);

}
 

public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {

    sort(begin(cand), end(cand));       
    func(0, cand, target, {});
    return vector<vector<int>>(begin(ans), end(ans));
    }
};
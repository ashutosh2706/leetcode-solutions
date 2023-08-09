class Solution {
public:
    set<vector<int>> st;
    vector<int> vec;
    void solve(int curr, int prev, vector<int> &nums) {
        if(curr == nums.size()) {
            if(vec.size() >= 2) st.insert(vec);
            return;
        }

        if(prev == -1 or nums[curr] >= nums[prev]) {
            vec.push_back(nums[curr]);
            solve(curr+1, curr, nums);
            vec.pop_back();
            solve(curr+1, prev, nums);
        } else solve(curr+1, prev, nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,-1,nums);
        return vector<vector<int>>(begin(st), end(st));
    }
};
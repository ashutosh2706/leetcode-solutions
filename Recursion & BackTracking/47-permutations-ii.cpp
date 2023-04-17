class Solution {
private:
set<vector<int>> st;

void permute(int ind, vector<int> &nums, vector<int> v) {
    if(ind == nums.size()) { 
        st.insert(v);
        return;
    }

    int tmp = -11;
    for(int i=0; i<nums.size(); i++) {

        if(nums[i] != -11) {
            v.push_back(nums[i]);
            swap(tmp, nums[i]);
            permute(ind+1, nums, v);
            v.pop_back();
            swap(tmp, nums[i]);
        }
    }
}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(0, nums, {});
        return vector<vector<int>>(begin(st), end(st));
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> arr(200, vector<int>{});
        int r = 0;
        arr[0].push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                arr[++r].push_back(nums[i]);
            } else {
                r = 0;
                arr[0].push_back(nums[i]);
            }
        }
        while(!arr.empty() and arr.back().empty()) arr.pop_back();
        return arr;
    }
};
class Solution {
public:
int permute(vector<int> nums, set<vector<int>> &set) {

    int n = nums.size(), ans = 0;
    for(int i=1; i<n; ++i) {
        for(int j=i+1; j<=n; ++j) {

            int e1 = nums[i-1], e2 = nums[j-1];
            if((e1%j == 0 or j%e1 == 0) and (e2%i == 0 or i%e2 == 0)) {
                swap(nums[i-1], nums[j-1]);
                if(set.count(nums) == 0) {
                    set.insert(nums);
                    ans = ans + 1 + permute(nums, set);
                }
            }

        }
    }
    return ans;
}
    int countArrangement(int n) { 
        vector<int> v;
        for(int i=1; i<=n; ++i) {
            v.emplace_back(i);
        }
        set<vector<int>> set;
        set.insert(v);
        return permute(v, set)+1;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> res;
    for(int i=1; i<=n; i++) res.emplace_back(i);
    for(int i=0; i<n; i++) res[nums[i] - 1] = 1e9;
    sort(begin(res), end(res));
    while(!res.empty() && res.back() == 1e9) res.pop_back();
    return res;

    }
};
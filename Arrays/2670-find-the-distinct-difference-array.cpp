
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
    vector<int> ans;

    unordered_map<int,int> f,b;
    for(int i=0; i<nums.size(); i++) {
        f[nums[i]]++;
    }
    for(auto& num : nums) {
        if(--f[num] == 0) {
            f.erase(num);
        }
        b[num]++;
        ans.push_back((int)b.size() - (int)f.size());
    }
    return ans;
    }
};
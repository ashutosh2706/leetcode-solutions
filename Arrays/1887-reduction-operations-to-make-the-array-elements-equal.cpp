class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); ++i) {
            mp[nums[i]]++;
        }
        vector<int> v;
        for(auto &p : mp) v.push_back(p.first);
        sort(begin(v), end(v), greater<int>());
        int cnt=0;
        for(int i=0; i<v.size()-1; ++i) {
            if(i == 0) {
                cnt += mp[v[i]];
            } else {
                mp[v[i]] += mp[v[i-1]];
                cnt += mp[v[i]];
            }
        }
        return cnt;
    }
};
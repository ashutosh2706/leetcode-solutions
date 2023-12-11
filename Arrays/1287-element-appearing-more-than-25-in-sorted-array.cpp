class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &a : arr) mp[a]++;
        int cnt=0, ans = 0;
        for(auto &[k,v] : mp) if(v > cnt) {
            cnt = v;
            ans = k;
        }
        return ans;
    }
};
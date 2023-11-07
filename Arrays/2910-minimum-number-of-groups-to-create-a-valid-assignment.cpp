class Solution {
public:
    long long solve(int sz, vector<int> &nums) {
        int l = sz, h = sz+1;
        long long groups = 0;
        for(auto &a : nums) {
            int q = a/h, r = a%h;
            while(r%l and q > 0) {
                --q;
                r = a-(h*q);
            }
            if(r%l) return 1e9;
            groups += (q + (r/l));
        }
        return groups;
    } 
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &a : nums) mp[a]++;
        vector<int> f;
        for(auto &[k,v] : mp) f.push_back(v);
        sort(begin(f), end(f));
        long long ans = 1e9;
        for(int i=1; i<=f[0]; ++i) {
            ans=min(ans, solve(i, f));
        }
        return ans;
    }
};
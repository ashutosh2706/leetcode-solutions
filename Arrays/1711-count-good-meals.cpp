class Solution {
public:
    int mod = 1e9+7;
    int countPairs(vector<int>& nums) {
    unordered_map<long long,long long> map;
    for(auto &a:nums) map[a]++;
    long long ans = 0;
    for(auto& i : nums) {
        if(map[i] > 0) {
            long long cnt = map[i];
            for(int x=0; x<=21; x++) {
                int r = (1<<x);
                if(2*i == r) 
                    ans = (ans + (cnt*(cnt-1))/2) % mod;
                else
                    ans = (ans + (map[i] * map[r-i])) % mod;
            }
            map[i] = 0;
        }
    }
    return ans % mod;
    }
};
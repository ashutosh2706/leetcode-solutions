class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<long long> res;
        for(auto &a : values) {
            for(auto &i : a) res.push_back(i);
        }
        long long ans = 0;   
        sort(begin(res), end(res));
        for(long long i=0; i<res.size(); ++i) {
            ans += res[i]*(i+1);
        }
        return ans;
    }
};
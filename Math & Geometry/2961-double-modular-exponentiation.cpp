class Solution {
public:
    long long power(long long x, long long y, long long p) {
        long long res=1;
        x = x%p;
        if(x==0) return 0;
        while (y > 0) { 
            if (y & 1) 
                res = (res*x) % p; 

            y = y>>1; 
            x = (x*x) % p;
        } 
        return res; 
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int i=0;
        vector<int> res;
        for(auto &v : variables) {
            long long a = v[0], b = v[1], c = v[2], m = v[3];
            long long r = power(a,b,10);
            r = power(r, c, m);
            if(r == target) res.push_back(i);
            ++i;
        }
        return res;
    }
};
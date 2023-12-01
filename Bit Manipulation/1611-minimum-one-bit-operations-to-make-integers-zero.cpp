class Solution {
public:
    typedef long long int ll;
    int minimumOneBitOperations(int n) {
        vector<ll> f(32);
        f[0]=1;
        for(int i=1; i<32; ++i) {
            f[i] = (ll)2*f[i-1] + 1;
        }

        vector<int> set_bits;
        for(int i=0; i<32; ++i) {
            if(n & (1<<i)) {
                set_bits.push_back(i);
            }
        }
        std::reverse(begin(set_bits), end(set_bits));
        ll sign = 1, ans = 0;
        for(auto &a : set_bits) {
            ans += (f[a]*sign);
            sign*=-1;
        }
        return ans;
    }
};

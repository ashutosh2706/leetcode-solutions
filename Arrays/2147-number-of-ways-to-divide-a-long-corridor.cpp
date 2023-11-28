class Solution {
public:
    typedef long long int ll;
    int mod = 1e9+7;
    int numberOfWays(string &s) {
    int n = s.length(), chairs = 0, cnt=1;
    ll ans=1;
    for(int i=0; i<n; ++i) {
        if(chairs != 0 and chairs % 2 == 0) {
            if(s[i] == 'P') cnt++;
            else {
                ans = (ans *cnt) % mod;
                cnt=1;
            }
        }
        if(s[i] == 'S') chairs++;
    }
    return (chairs!=0 and chairs%2 == 0) ? ans : 0;
    }
};

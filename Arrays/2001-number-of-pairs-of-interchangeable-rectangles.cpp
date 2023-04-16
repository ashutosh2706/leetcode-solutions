class Solution {
#define ld long double
#define ll long long
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {

    map<ld, int> mp;

    for(auto &a:nums) mp[(ld)a[0] / (ld)a[1]]++;

    ll pairs = 0;
    for(auto &a:mp) {
        ll n = a.second;
        if(n > 1)
        pairs += (ll)(n*(n-1))/2;
    }

    return pairs;

    }
};
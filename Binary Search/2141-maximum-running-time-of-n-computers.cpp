class Solution {
public:
    typedef long long int ll;
    long long maxRunTime(int n, vector<int>& batteries) {
    ll lo = *min_element(begin(batteries), end(batteries)), ts = 0, mid, hi;
    for(auto &a : batteries) ts += a;
    hi = ts/n;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(posssible(mid, batteries, n)) lo = mid+1;
        else hi = mid-1;
    }
    return hi;  

    }

    bool posssible(ll mini, vector<int> &batteries, ll n) {
    ll total = n * mini;
    ll sum = 0;
    for(auto &a : batteries) {
        sum += min((ll)a, mini);
        if(sum >= total) return 1;
    }
    return 0;
    }
};
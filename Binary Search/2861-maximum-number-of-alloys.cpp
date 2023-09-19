class Solution {
public:
typedef long long int ll;
int bs(vector<int> &comp, ll budget, vector<int> &cost, vector<int> &stock) {

    ll lo = 0, hi = INT_MAX, mid;
    while(lo <= hi) {
        mid = lo+(hi-lo)/2;
        ll sum = 0;
        
        for(int i=0; i<cost.size(); i++) {
            ll req = (ll)comp[i] * (ll)mid;
            if((ll)stock[i] >= req) req = 0;
            else req -= stock[i];
             sum += (ll)req * (ll)cost[i];
            if(sum > budget) break;
        }
        if(sum > budget) hi = mid-1;
        else lo = mid+1;
    }
    return hi;
}
    
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    
        int ms = 0;
        for(auto &v : composition) {
            ms = max(ms, bs(v, budget, cost, stock));
        }
        return ms;
    }
};
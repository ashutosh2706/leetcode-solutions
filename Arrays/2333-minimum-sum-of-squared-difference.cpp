class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

    typedef long long int ll;
    ll tot = k1 + k2;
    map<ll, ll> map;
    for(int i=0; i<nums1.size(); i++) {
        map[abs(nums1[i] - nums2[i])]++;
    }

    while(!map.empty() and tot > 0) {

        auto it = prev(end(map));
        ll ele = it->first, cnt = it->second;

        if(cnt < tot) {
            map.erase(ele);
            tot -= cnt;
            if(ele-1 > 0) map[ele-1] += cnt;
        } else if(cnt > tot) {
            if(ele-1 > 0) map[ele-1] += tot;
            map[ele] = (cnt-tot);
            tot = 0;
        } else {
            if(ele-1 > 0) map[ele-1] += tot;
            tot = 0;
            map.erase(ele);
        }

    }
    ll ans = 0;
    for(auto& [x, y] : map) {
        ans += ((x*x) * y);
    }
    return ans;

    }
};
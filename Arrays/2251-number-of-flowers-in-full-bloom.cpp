class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<pair<int,int>> vp;
    for(int i=0; i<people.size(); ++i) {
        vp.push_back({people[i], i});
    }
    
    sort(begin(vp), end(vp), [](auto &p1, auto &p2){
        return p1.first < p2.first;
    });

    vector<int> f1;
    for(auto &a : flowers) f1.push_back(a[1]);
    sort(begin(flowers), end(flowers));
    sort(begin(f1), end(f1));
    vector<int> ans(vp.size());
    int p = 0, cnt = 0;
    for(int i=0; i<vp.size(); ++i) {
        while(p < flowers.size() and flowers[p][0] <= vp[i].first) {
            cnt++;
            p++;
        }
        auto it = lower_bound(begin(f1), end(f1), vp[i].first) - begin(f1);
        ans[vp[i].second] = cnt-it;
    }
    return ans;
    }
};
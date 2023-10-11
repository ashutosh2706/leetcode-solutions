class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, en;
        for(auto &v:flowers) {
            start.push_back(v[0]);
            en.push_back(v[1]);
        }
        sort(begin(start),end(start));
        sort(begin(en),end(en));
        vector<int> ans;
        for(auto &i : people) {
            auto alive = upper_bound(begin(start), end(start), i) - begin(start);
            auto died = lower_bound(begin(en), end(en), i) - begin(en);
            ans.push_back(alive-died);
        }
        return ans;
    }
};
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
    sort(begin(nums),end(nums));
    map<int,int> map;
    for(auto &num:nums) map[num%space]++;
    int cnt = 0;
    vector<int> rems;
    for(auto &p:map) {
        if(p.second == cnt) rems.push_back(p.first);
        else if(p.second > cnt) {
            cnt = p.second;
            rems.clear();
            rems.push_back(p.first);
        }
    }
    int ans = 1e9;
    for(auto &r:rems) {
        for(auto &i:nums) {
            if(i%space == r) {
                ans = min(ans, i);
                break;
            }
        }
    }
    return ans;
    }
};
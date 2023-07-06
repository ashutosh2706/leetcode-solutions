class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
    map<int,int> map;
    for(auto& i:nums) map[i]++;
    int ans = 0;
    while(!map.empty()) {
        int e = map.begin()->first, c = (map.begin()->second)-1;
        map.erase(e);
        if(c == 0) continue;
        ans += c;
        map[e+1] += c;
    }
    return ans;
    }
};
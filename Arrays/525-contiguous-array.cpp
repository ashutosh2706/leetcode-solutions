class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        unordered_map<int,int> map;
        map[0] = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]) cnt++;
            else cnt--;
            if(map.count(cnt)) {
                ans = max(ans, i-map[cnt]);
            }else {
                map[cnt] = i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); ++i) mp[nums[i]]++;
        int cnt = 0;
        for(auto &p : mp) {
            if(p.second == 1) return -1;
            else {
                if(p.second % 3 == 0) cnt += p.second/3;
                else {
                        while(p.second>0 and p.second % 3 != 0) {
                            p.second -= 2;
                            cnt++;
                        }
                        cnt += p.second / 3;
                    }
            }
        }
        return cnt;
        
    }
};
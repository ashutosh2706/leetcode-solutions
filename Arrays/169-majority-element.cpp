class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=0,cnt=0;
        for(int i:nums) {
            if(cnt==0) cand=i;
            if(cand==i) cnt++;
            else cnt--;
        }
        return cand;
    }
};
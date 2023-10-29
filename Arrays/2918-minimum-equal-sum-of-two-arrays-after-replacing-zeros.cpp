class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        int g1 = 0, g2 = 0;
        for(auto &a : nums1) {
            s1+=a;
            if(a == 0) g1++;
        }
        for(auto &a: nums2) {
            s2+=a;
            if(a == 0) g2++;
        }
        
        if(g1 and g2) return max(s1+g1, s2+g2);
        if(g1==0 and g2==0) return (s1 == s2) ? s1 : -1;
        if(g1 == 0) {
            if((s2 + g2) > s1) return -1;
            else return s1;
        }
        if(g2 == 0) 
            if((s1+g1) > s2) return -1;
        return s2;
        
    }
};
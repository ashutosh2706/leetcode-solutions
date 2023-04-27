class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
    int x = m-1,y=n-1;
    int last = nums1.size()-1;
    while(x>=0 && y>=0 && last>=0) {
        if(nums1[x]>nums2[y]) nums1[last--] = nums1[x--];
        else if(nums1[x]<nums2[y]) nums1[last--] = nums2[y--];
        else if(nums2[y]==nums1[x]) { nums1[last--] = nums1[x--]; nums1[last--]=nums2[y--]; }
    }
    while(y>=0) nums1[last--]=nums2[y--];
    }
};
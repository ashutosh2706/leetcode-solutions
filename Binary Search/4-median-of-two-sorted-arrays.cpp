class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size(), n2 = nums2.size();
    int n = (n1+n2) >> 1;
    int l = 0, h = n1;
    while(l <= h) {

        int m1 = l + (h-l)/2;
        int m2 = n - m1;
        int a = m1 == 0 ? INT_MIN : nums1[m1-1];
        int b = m1 == n1 ? INT_MAX : nums1[m1];
        int c = m2 == 0 ? INT_MIN : nums2[m2-1];
        int d = m2 == n2 ? INT_MAX : nums2[m2];
        if(a <= d and c <= b) {
            return (n1+n2)%2 == 0 ? (double)(max(a,c) + min(b,d))/2 : min(b,d);
        }
        if(a > d) h = m1 - 1;
        else if(c > b) l = m1 + 1;
    }
    return 0.0;

    }
};
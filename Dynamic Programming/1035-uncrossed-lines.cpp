class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    
    int n1 = nums1.size(), n2 = nums2.size();
    int A[501][501];
    memset(A, -1, sizeof(A));
    for(int i=n1-1; i>=0; i--) 
        for(int j=n2-1; j>=0; j--) 
            if(nums1[i] == nums2[j])
                A[i][j] = 1 + A[i+1][j+1];
            else A[i][j] = max(A[i+1][j], A[i][j+1]);

    return A[0][0]+1;
    }
};
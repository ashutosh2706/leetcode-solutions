class Solution {
public:
    int f(vector<int> &arr) {
        int mini = arr[0], maxi = arr[0];
        for(auto &a : arr) {
            mini = min(mini, a);
            maxi = max(maxi, a);
        }
        return maxi-mini;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> s1(n), s2(n), s3(n), s4(n);
        for(int i=0; i<n; ++i) {
            s1[i] = arr1[i] + arr2[i] + i;
            s2[i] = arr1[i] + arr2[i] - i;
            s3[i] = arr1[i] - arr2[i] + i;
            s4[i] = arr1[i] - arr2[i] - i;
        }

        return max({f(s1), f(s2), f(s3), f(s4)});
    }
};
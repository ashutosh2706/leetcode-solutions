class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp(n);
        int maxi = arr[n-1];
        tmp[n-1] = -1;
        for(int i=n-2; i>=0; i--) {
            tmp[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return tmp;
    }
};
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(begin(arr), end(arr));
    arr[0] = 1;
    int ans = 0;
    for(auto i = 1; i<arr.size(); ++i) {
        if((arr[i]-arr[i-1]) > 1) {
            arr[i] = 1+arr[i-1];
            ans = max(ans, arr[i]);
        }
    }
    return arr.back();
    }
};
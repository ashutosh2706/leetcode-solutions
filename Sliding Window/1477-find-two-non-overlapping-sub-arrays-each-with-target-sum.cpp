class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0, ans = 1e9, len=1e9;
        vector<int> mini(arr.size(), 1e9);
        for(int i=0,j=0; j<arr.size(); ++j) {
            sum += arr[j];
            while(sum > target) sum -= arr[i++];
            if(sum == target) {
                int ln = j-i+1;
                if(i > 0) ans = min(ans, ln + mini[i-1]);
                // minimum length found so far
                len = min(len, ln);
            }
            mini[j] = len;
        }
        return ans == 1e9 ? -1 : ans;
    }
};
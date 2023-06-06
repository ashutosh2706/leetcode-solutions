class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int cd = arr[1] - arr[0];
        for(int i=2; i<arr.size(); i++) {
            if(arr[i] - arr[i-1] != cd) return 0;
        }
        return 1;
    }
};
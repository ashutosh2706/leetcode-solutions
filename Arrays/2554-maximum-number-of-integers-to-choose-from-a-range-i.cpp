class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        unordered_set<int> set(begin(nums), end(nums));
        int sum = 0, cnt = 0;
        for(int i=1; i<=n; ++i) {
            if(set.count(i) == 0) {
                if(sum + i > maxSum) break;
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
};
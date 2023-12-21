class Solution {
public:
    int palin(long long n) {
        string s = to_string(n);
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return 0;
            ++l;
            --r;
        }

        return 1;
    }
    long long minimumCost(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        long long med =
            n & 1 ? nums[n / 2] : (nums[n / 2] + nums[(n / 2) - 1]) / 2;

        long long left = med, right = med;
        while (!palin(left))
            --left;
        while (!palin(right))
            ++right;

        long long sum = 0, cost = LLONG_MAX;
        for (auto& a : nums) {
            sum += abs(a - left);
        }
        cost = min(cost, sum);
        sum = 0;
        for (auto& a : nums) {
            sum += abs(a - right);
        }
        return min(cost, sum);
    }
};
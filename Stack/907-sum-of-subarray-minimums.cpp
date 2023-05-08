class Solution {
const unsigned int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& nums) {

    vector<int> left, right;
    stack<int> S,T;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(i == 0) {
            S.push(i);
            left.push_back(-1);
            continue;
        }
        while(!S.empty() and nums[S.top()] >= nums[i]) S.pop();
        S.empty() ? left.push_back(-1) : left.push_back(S.top());
        S.push(i);
    }
    for(int i=n-1; i>=0; i--) { 
        if(i == n - 1) {
            right.push_back(n);
            T.push(i);
            continue;
        }
        while(!T.empty() and nums[T.top()] > nums[i]) T.pop();
        T.empty() ? right.push_back(n) : right.push_back(T.top());
        T.push(i);
    }
    reverse(begin(right), end(right));

        long long sum = 0;
        for(int i=0; i<n; i++) {
            long long le = i - left[i];
            long long ri = right[i] - i;
            long long tot = le * ri * nums[i] % mod;
            sum = (sum + tot) % mod;
        }

        return sum;
    }
};
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        typedef long long int ll;
        int n = nums.size();
        vector<ll> left(n), right(n);
        vector<int> st;
        for(int i=0; i<n; ++i) {
                while(!st.empty() and nums[st.back()] >= nums[i]) st.pop_back();
                if(st.empty()) {
                    left[i] = (ll)(i+1) * (ll)nums[i];
                } else {
                    left[i] = left[st.back()] + (ll)(i-st.back()) * (ll)nums[i];
                }
                st.push_back(i);
        }
        st.clear();
        for(int i=n-1; i>=0; --i) {
                while(!st.empty() and nums[st.back()] >= nums[i]) st.pop_back();
                if(st.empty()) {
                    right[i] = (ll)(n-i) * (ll)nums[i];
                } else {
                    right[i] = right[st.back()] + (ll)(st.back()-i) * (ll)nums[i];
                }
                st.push_back(i);
        }
        ll ans = 0;
        for(int i=0; i<n; ++i) {
                ans = max(ans, left[i]+right[i]-nums[i]);
        }
        return ans;
    }
};
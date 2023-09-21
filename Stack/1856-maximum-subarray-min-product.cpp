class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        typedef long long int ll;
        int n = nums.size();
        vector<ll> pf;
        ll sum = 0, ans=0;
        for(int i=0; i<n; ++i) {
            pf.emplace_back(sum+=nums[i]);
        }
        vector<ll> left(n), right(n), st;
        for(int i=0; i<n; ++i) {
            while(!st.empty() and nums[st.back()] >= nums[i]) st.pop_back();
            if(st.empty()) left[i] = 0;
            else left[i] = st.back()+1;
            st.emplace_back(i);
        }
        st.clear();
        for(int i=n-1; i>=0; --i) {
            while(!st.empty() and nums[st.back()] >= nums[i]) st.pop_back();
            if(st.empty()) right[i] = n-1;
            else right[i] = st.back()-1;
            st.emplace_back(i);
        }
        for(int i=0; i<n; ++i) {
            if(left[i] == 0) ans = max(ans, (ll)nums[i] * pf[right[i]]);
            else ans = max(ans, (ll)nums[i] * (pf[right[i]] - pf[left[i]-1]));
        }
        return ans%(int)(1e9+7);
    }
};
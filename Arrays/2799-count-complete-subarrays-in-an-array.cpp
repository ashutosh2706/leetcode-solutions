class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

    int cnt  =st.size(), ans = 0;

    for(int i=0; i<nums.size(); i++) {
        unordered_set<int> set;
        for(int j=i; j<nums.size(); j++) {

            set.insert(nums[j]);
            if(set.size() == cnt) ans++;

        }
    }
    return ans;
    }
};
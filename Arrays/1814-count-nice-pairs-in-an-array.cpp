class Solution {
private:
    int rev(int &a) {
        string s = to_string(a);
        string r = s;
        reverse(begin(r), end(r));
        return stoi(s) - stoi(r);
    }
public:
    int mod = 1e9+7;
    int countNicePairs(vector<int>& nums) {
    vector<int> diff(nums.size());
    for(int i=0; i<nums.size(); ++i) {
        diff[i] = rev(nums[i]);
    }

    long long cnt = 0;
    unordered_map<int, int> mp;
    for(auto &i : diff) {
        cnt = (cnt + mp[i]) % mod;
        ++mp[i];
    }

    return cnt%mod;
    }
};
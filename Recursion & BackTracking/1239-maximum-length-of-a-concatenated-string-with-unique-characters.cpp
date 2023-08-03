class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> v(26);
        return solve(0, arr, v);

    }
    
    int solve(int ind, vector<string> &arr, vector<int> &v) {
        if(ind == arr.size()) return 0;
        int ans = 0;
        for(int i=ind; i<arr.size(); i++) {
            bool b = 0;
            unordered_set<char> set(begin(arr[i]), end(arr[i]));
            if(set.size() != arr[i].length()) continue;
            for(auto &c : arr[i]) {
                if(v[c-'a']) {
                    b = 1;
                    break;
                }
            }
            if(b == 0) {
                for(auto &c : arr[i]) v[c-'a']++;
                ans = max(ans, (int)arr[i].length() + solve(i+1, arr, v));
                for(auto &c : arr[i]) v[c-'a']--;
            }
        }
        return ans;
    }
};
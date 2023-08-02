class Solution {
public:
    string ss;
    int solve(string s, unordered_set<string> &set, int &n) {
        if(s.length() == n) {
            if(set.count(s)) return 0;
            ss = s;
            return 1;
        }
        int b;
        s.push_back('1');
        b = solve(s, set, n);
        if(b) return 1;
        s.pop_back();
        s.push_back('0');
        b = solve(s, set, n);
        s.pop_back();
        return b;

    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> set(nums.begin(), nums.end());
        solve("", set, n);
        return ss;
    }
};
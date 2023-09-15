class Solution {
public:
int check(int ind, string &s, int sum) {
    if(sum == 0 and ind == s.length()) return 1;
    if(sum < 0) return 0;
    string res;
    int ans = 0;
    for(int i=ind; i<s.length(); ++i) {
        res += s[i];
        ans = ans or check(i+1, s, sum-stoi(res));
    }
    return ans;
}
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1; i<=n; ++i) {
            string ss = to_string(i*i);
            if(check(0, ss, i)) {
                cout << ss << " " << i << endl;
                sum += i*i;
            }
        }
        return sum;
    }
};
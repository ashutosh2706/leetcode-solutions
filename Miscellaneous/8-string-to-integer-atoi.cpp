class Solution {
public:
    int myAtoi(string s) {
        int N = s.length(), sign = 1, i = 0;
        while(i < N and s[i] == ' ') i++;
        if(s[i] == '+' or s[i] == '-' or isdigit(s[i])) {
            if(s[i] == '-' or s[i] == '+') {
                if(s[i] == '-') sign = -1;
                i++;
            }
            long long ans = 0;
            while(i<N and isdigit(s[i])) {
                ans = (ans * 10) + (s[i++] - '0');
                if(ans > INT_MAX) break;
            }
            ans *= sign;
            if(ans > INT_MAX) return INT_MAX;
            if(ans < INT_MIN) return INT_MIN;
            return ans;
        }
        return 0;
    }
};
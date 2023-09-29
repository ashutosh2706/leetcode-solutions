class Solution {
public:
    int maximumSwap(int num) {
        if(num >= 0 and num < 10) return num;
        string s = to_string(num);
        int ans = num;
        for(int i=0; i<s.length(); ++i) {
            for(int j=i+1; j<s.length(); ++j) {
                swap(s[i],s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return ans;
    }
};
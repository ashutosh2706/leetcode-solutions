// Time: O(4^n)
// Space: O(2^n)

class Solution {
public:
    int maxProduct(string s) {
        
    int n = s.length();
    
    auto isPalin = [](string str) {
        string r = str;
        reverse(begin(str), end(str));
        return str == r;
    };

    vector<pair<int, int>> mp;
    for(int mask = 1; mask < (1 << n); mask++) {

        string sub = "";
        for(int i=0; i<n; i++) {
            if(mask & (1 << i)) sub += s[i];
        }
        if(isPalin(sub)) mp.push_back({mask, sub.length()});

    }

    int ans = 0;
    for(int i=0; i<mp.size()-1; i++) {
        for(int j=i+1; j<mp.size(); j++) {
            if((mp[i].first & mp[j].first) == 0) ans = max(ans, (mp[i].second * mp[j].second));
        }
    }
    return ans;

    }
};
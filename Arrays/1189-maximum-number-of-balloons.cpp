class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
    map<char, int> mp;
    for(auto &c:text) mp[c]++;

    int cnt = 0, i = 0;
    string b = "balloon";
    while(true) {
        if(i == b.length()) {
            i = 0;
            cnt++;
        }
        if(mp[b[i]] == 0) break;
        mp[b[i++]]--;
    }
    return cnt;

    }
}; 
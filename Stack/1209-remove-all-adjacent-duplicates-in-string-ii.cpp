class Solution {
public:
    string removeDuplicates(string s, int k) {
        
    stack<pair<char, int>> S;
    S.push({s[0], 1});
    for(int i=1; i<s.length(); i++) {

        if(!S.empty() && S.top().first == s[i]) {
            S.push({s[i], S.top().second + 1});

            if(S.top().second == k) {
                int c = k;
                while(c--) S.pop();

            }
        } else {
            S.push({s[i], 1});
        }
    }

    // out(S)

    string res;
    while(!S.empty()) {
        res += S.top().first;
        S.pop();
    }

    reverse(begin(res), end(res));
    return res;
    }
};
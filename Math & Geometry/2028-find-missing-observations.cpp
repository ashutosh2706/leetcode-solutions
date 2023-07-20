class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        typedef long long int ll;
        ll sum = accumulate(begin(rolls), end(rolls), 0);
        ll rem = (mean * (n + rolls.size())) -  sum;

        if(rem < n or rem > (6*n)) return {};
        vector<int> res(n, 1);
        rem -= n;
        for(int i=0; i<n; i++) {
            if(rem >= 5) {
                res[i] += 5;
                rem -= 5;
            } else {
                res[i] += rem;
                rem = 0;
            }
            if(rem <= 0) break;
        }
        return res;
    }
};
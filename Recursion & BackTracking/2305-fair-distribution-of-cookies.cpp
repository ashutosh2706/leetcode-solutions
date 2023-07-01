class Solution {
public:
    int solve(int ind, vector<int>& cookies, vector<int> sums) {

        if(ind == cookies.size()) {
            return *max_element(begin(sums), end(sums));
        }

        int ans = INT_MAX;
        for(int i=0; i<sums.size(); i++) {
            sums[i] += cookies[ind];
            ans = min(ans, solve(ind+1, cookies, sums));
            sums[i] -= cookies[ind];
            if(sums[i] == 0) break;
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sums(k);
        return solve(0,cookies,sums);
    }
};
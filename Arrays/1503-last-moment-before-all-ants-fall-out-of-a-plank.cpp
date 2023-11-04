class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto &a : right) ans = max(ans, n-a);
        for(auto &a : left) ans = max(ans, a);
        return ans; 
    }
};
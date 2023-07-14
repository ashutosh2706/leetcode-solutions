class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        int a = -1, b = -1, c = -1;
        for(int i=0; i<t.size(); i++) {
            if(t[i][0] > target[0] or t[i][1] > target[1] or t[i][2] > target[2]) continue;
            a = max(a, t[i][0]);
            b = max(b, t[i][1]);
            c = max(c, t[i][2]);

            if(target == vector<int>{a,b,c}) return 1;
        }
        return 0;
    }
};
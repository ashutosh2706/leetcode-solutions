class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        int ans = 0, cover = 0;
        sort(begin(t), end(t));
        for(int i=0, j=0; ans < len && j < t.size(); ) {
            if(t[i][0] + len > t[j][1]) {
                cover += t[j][1] - t[j][0] + 1;
                ans = max(ans, cover);
                j++;
            } else {
                int part = max(0, t[i][0] + (len - t[j][0]));
                ans = max(ans, cover + part);
                cover -= (t[i][1] - t[i][0] + 1);
                i++;
            }
        }
        return ans;
    }
};



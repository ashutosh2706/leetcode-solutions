class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    sort(begin(points), end(points));
    int ind = 0, N = points.size(), ans = 0;
    while(ind < points.size()) {

        int s = points[ind][1], i = ind+1;
        while(i < N and points[i][0] <= s) {
            s = min(s, points[i][1]);
            i++;
        } 
        ans++;
        ind = i;
    }
    return ans;
    }
};
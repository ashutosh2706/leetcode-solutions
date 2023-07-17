
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });
    int x1 = intervals[0][0], y1 = intervals[0][1];
    int ans = 0;
    for(int i=1; i<intervals.size(); i++) {
        int x2 = intervals[i][0], y2 = intervals[i][1];
        if(x2 >= x1 and y2 <= y1) {
            ans++;
        } else {
            x1 = x2;
            y1 = y2;
        }
    }   
    return intervals.size() - ans;
    }
};
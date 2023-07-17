class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int ans = 0;
        int x1 = intervals[0][0], y1 = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            int x2 = intervals[i][0], y2 = intervals[i][1];
            if(x2 >= y1) {
                x1 = x2;
                y1 = y2;
                continue;
            }

            if(x2 >= x1 and y2 <= y1) {
                ans++;
                x1 = x2;
                y1 = y2;
            } else if(x2 >= x1 and y2 > y1) {
                ans++;
            }
        }
        return ans;
    }
};
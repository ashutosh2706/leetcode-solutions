class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), a = newInterval[0], b = newInterval[1];
        vector<vector<int>> res;
        int start = 0, x = a, y = b;
        for(; start<n; start++) {
            if(a > intervals[start][0] and a > intervals[start][1]) {
                res.push_back(intervals[start]);
                continue; 
            }
            x = (a < intervals[start][0]) ? a : intervals[start][0];
            break;
        }
        for(; start<n; start++) {
            if(b > intervals[start][0] and b > intervals[start][1]) continue; 
            y = (b < intervals[start][0]) ? b : intervals[start][1];
            break;
        }
        if(start < n) {
            if(intervals[start][1] == y) start++;
            res.push_back({x,y});
            while(start < n) res.push_back(intervals[start++]);
        } else res.push_back({x,y});    
        return res;
    }
};
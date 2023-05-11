class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto getDistance = [](long x, long y) {
            x = abs(x);
            y = abs(y);
            return sqrt(pow(x,2) + pow(y,2));
        };
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        for(int i=0; i<points.size(); i++)
            pq.push({getDistance(points[i][0], points[i][1]), i});
            
        vector<vector<int>> res;
        while(!pq.empty() and res.size() < k) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};



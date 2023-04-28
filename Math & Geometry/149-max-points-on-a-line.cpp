class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
    if(points.size() == 1) return 1;
        
    int ans = 0;
    for(int i=0; i<points.size(); i++) {
       
        map<double, int> mp;
        for(int j=i+1; j<points.size(); j++) {

            double slope;
            if(points[j][0] - points[i][0] == 0) slope = 1e9;
            else {
                slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
            } 
            mp[slope]++;
        }

        int tmp = 0;
        for(auto &P : mp) {
            tmp = max(tmp, P.second + 1);
        }
        ans = max(ans, tmp);

    }
    return ans;
    }
};
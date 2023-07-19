class DetectSquares {
public:
    map<pair<int,int>, int> map;
    DetectSquares() {}
    
    void add(vector<int> point) {
        map[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for(auto &p : map) {
            int i = p.first.first, j = p.first.second;
            if(i == x) continue;
            if(j == y) {
                int dist = abs(x - i);
                ans += (map[{i,j}] * map[{i,j+dist}] * map[{x, y+dist}]);
                ans += (map[{i,j}] * map[{i,j-dist}] * map[{x, y-dist}]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> map;
        for(auto &i:ans) {
            map[i]++;
        }
        int res = 0;
        for(auto &p : map) {
            int a = p.first, b = p.second;
            while(b) {
                if(b >= a+1) {
                    b -= (a+1);
                } else {
                    b = 0;
                }
                res += (a+1);
            }
        }
        return res;
    }
};
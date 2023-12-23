class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> st;
        st.insert({0,0});
        for(auto &c : path) {
            if(c == 'N') ++y;
            if(c == 'S') --y;
            if(c == 'E') ++x;
            if(c == 'W') --x;
            if(st.count({x,y})) return 1;
            st.insert({x,y});
        }
        return 0;
    }
};
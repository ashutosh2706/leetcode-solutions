class Solution {
public:
    bool winnerOfGame(string &colors) {
        int n = colors.size();
        int alice = 0, bob = 0, l=0,r=0;
        for(; r<n; ++r) {
            if(colors[r] == colors[l] and colors[l] == 'A') continue;
            if((r-l) > 2) alice += (r-l)-2;
            l = r;
        }
        if((r-l)>2) alice += (r-l)-2;
        l=0,r=0;
        for(; r<n; ++r) {
            if(colors[r] == colors[l] and colors[l] == 'B') continue;
            if((r-l) > 2) bob += (r-l)-2;
            l = r;
        }
        if((r-l)>2) bob += (r-l)-2;
        cout << alice << " " << bob;
        return alice > bob;
    }
};
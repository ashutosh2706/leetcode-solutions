class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if((sx == fx and sy == fy) and t == 1) return 0;
        int dx = abs(sx-fx), dy = abs(sy-fy);
        int mini = min(dx,dy), r;
        t -= mini;
        sx < fx ? sx += mini : sx -= mini;
        sy < fy ? sy += mini : sy -= mini;
        r = (sx == fx) ? abs(fy-sy) : abs(fx-sx);
        return r <= t; 
    }
};
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hr) {
    int lo = 1, hi = 1e9, mid;
    while(lo <= hi) {
        mid = lo+(hi-lo)/2;
        if(posssible(mid, dist, hr)) {
            hi = mid-1;
        }else lo = mid+1;
    }
    if(lo >= 1e9) return -1;
    return lo;
    }

    bool posssible(int h, vector<int> &list, double h2) {
    double time = 0;
    for(int i=0; i<list.size()-1; i++) {
        double d = (double)list[i]/(double)h;
        if(time + d > h2) return 0;
        time += ceil(d);
    }

    time += (double)list.back()/(double)h;
    return time <= h2;
}
};
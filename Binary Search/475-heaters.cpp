class Solution {
private:
int check(vector<int> &houses, vector<int>& heaters, int &range) {
    int ind = 0, i = 0;
    while(i < houses.size() and ind < heaters.size()) {
        if(houses[i] >= (heaters[ind]-range) and houses[i] <= (heaters[ind]+range)) i++;
        else ind++;
    }
    return i >= (int)houses.size();

}
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));
        int lo = 0, hi =  INT_MAX, mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            check(houses,heaters,mid) ? hi = mid-1 : lo=mid+1;
        }

        return lo;
        
    }
};
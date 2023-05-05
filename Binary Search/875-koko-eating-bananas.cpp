class Solution {
public:
int canEat(vector<int> &piles, int k, int hr) {
    int total = 0;
    for(int i=0; i<piles.size(); i++) {
        if(total > hr) return 0;
        int n = piles[i];
        if(n > k) {
            if(n % k == 0) total += n/k;
            else total += floor(n/k) + 1; 
        } else total++; 
    }
    return total > hr ? 0 : 1;
}
    int minEatingSpeed(vector<int>& piles, int hr) {
    int l = 1, h = *max_element(piles.begin(), piles.end());
    while(l <= h) {
        int mid = l+(h-l)/2;
        if(canEat(piles,mid,hr)) h = mid-1;
        else l = mid+1;
    }
    return l;
    }
};
class Solution {
public:
    int bs(long &day, vector<int> &arr, long m, long &k) {
    int cnt = 0;
    for(auto &i:arr) {
        if(i <= day) cnt++;
        else cnt = 0;
        if(cnt == k) {
            m--;
            cnt = 0;
        }
    }
    return m <= 0;
    }

    int minDays(vector<int>& arr, long m, long k) {

    if((long)arr.size() < (long)m*k) {
       return -1;
    }
    long lo = *min_element(begin(arr), end(arr)), hi = *max_element(begin(arr), end(arr)), mid;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(bs(mid, arr, m, k)) hi = mid-1;
        else lo = mid+1;
    }
    return lo;

    }
};
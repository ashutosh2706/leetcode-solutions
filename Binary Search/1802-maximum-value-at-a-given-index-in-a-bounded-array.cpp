class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long lo = 1, hi = maxSum, mid;
        while(lo <= hi) {
            mid = lo+(hi-lo)/2;
            long long sum1, sum2;
            if(mid - index <= 0) {
                sum1 = (mid*(mid+1))/2;
                sum1 += index-mid+1;
            } else sum1 = ((2*mid-index)*(index+1))/2;
            int cnt = n-1-index;
            if(mid - cnt <= 0) {
                sum2 = (mid*(mid-1))/2;
                sum2 += cnt-mid+1;
            } else sum2 = (cnt*(2*mid-1-cnt))/2;
            long long total = sum1+sum2;
            total <= maxSum ? lo=mid+1 : hi=mid-1;
        }
        return hi;
    }
};
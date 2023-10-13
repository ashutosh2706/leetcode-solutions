class Solution {
public:
    int peak(MountainArray &arr) {
        int n = arr.length();
        int lo = 0, hi=n-1, mid;
        while(lo < hi) {
            mid = lo+(hi-lo)/2;
            if(arr.get(mid) < arr.get(mid+1)) lo = mid+1;
            else hi=mid-1; 
        }
        return lo;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        
        int pk = peak(arr);
        int lo = 0, hi = pk, mid;
        cout << pk << endl;
        while(lo <= hi) {
            mid = lo+(hi-lo)/2;
            if(arr.get(mid) == target) return mid;
            if(arr.get(mid) < target) lo = mid+1;
            else hi = mid-1;
        }

        lo = peak(arr)+1, hi = arr.length()-1;
        while(lo <= hi) {
            mid=lo+(hi-lo)/2;
            if(arr.get(mid) == target) return mid;
            if(arr.get(mid) < target) hi = mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
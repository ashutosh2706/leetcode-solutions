class Solution {
public:
    int minimumSum(int n, int k) {
    set<int> set;
    for(int i=(k/2)+1; i<k; ++i) set.insert(i);
    int sum = 0;
    for(int i=1, cnt = 0; cnt < n; i++) {
        if(set.count(i)) continue;
        sum+=i;
        cnt++;
    }
    return sum;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg = accumulate(begin(gas),end(gas), 0);
        int tc = accumulate(begin(cost), end(cost), 0);
        if(tg - tc < 0) return -1;
        int N = gas.size();
        vector<pair<int,int>> v(2*N);
        for(int i=0; i<gas.size(); ++i)
            v[i] = {gas[i]-cost[i], i};
        for(int i=N; i<v.size(); ++i) 
            v[i] = v[i - N];
        long sum = 0;
        for(int l=0, r=0; r<v.size(); r++) {
            sum += v[r].first;
            while(sum < 0) {
                sum -= v[l].first;
                l++;
            }
            if((r - l + 1) == N) return v[l].second;
        }
        return -1;
    }
};
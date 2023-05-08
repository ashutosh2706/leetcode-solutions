class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(begin(gas), end(gas), 0) < accumulate(begin(cost), end(cost), 0)) 
            return -1;
        
        int start = 0, sum = 0;
        for(int i=0; i<gas.size(); i++) {
            sum += gas[i] - cost[i];
            if(sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        return start;
    }
};
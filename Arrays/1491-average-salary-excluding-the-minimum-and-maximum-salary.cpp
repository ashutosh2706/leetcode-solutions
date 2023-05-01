class Solution {
public:
    double average(vector<int>& sal) {
        sort(begin(sal), end(sal));
        int sum = accumulate(begin(sal), end(sal), 0);
        sum -= (sal.front() + sal.back());
        double avg = (double)sum / (double)(sal.size() - 2);
        return avg;
    }
};
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        if(target == 0 || target == 1) return target;
        int sum = 0, steps = 1;
        while(sum < target) {
            sum += steps;
            steps++;
        }
        while((sum - target) % 2 != 0) {
            sum += steps;
            steps++;
        }
        return steps - 1;
    }
};


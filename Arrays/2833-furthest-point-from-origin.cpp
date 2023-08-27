class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int sum = 0, cnt = 0;
        for(auto &c:moves) {
            if(c == 'L') sum -= 1;
            else if(c == 'R') sum += 1;
            else cnt++;
        }
        return max(abs(sum - cnt), abs(sum + cnt));
    }
};
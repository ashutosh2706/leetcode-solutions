class Solution {
public:
    bool isRobotBounded(string inst) {

        map<pair<char,char>, char> dir;
        dir[{'N','L'}] = 'W';
        dir[{'N','R'}] = 'E';
        dir[{'W','L'}] = 'S';
        dir[{'W','R'}] = 'N';
        dir[{'S','L'}] = 'E';
        dir[{'S','R'}] = 'W';
        dir[{'E','L'}] = 'N';
        dir[{'E','R'}] = 'S';

        char curr = 'N';
        int x = 0, y = 0;

        for(auto &c : inst) {

            if(c == 'G') {
                if(curr == 'N') y++;
                else if(curr == 'S') y--;
                else if(curr == 'W') x--;
                else x++;
            } else curr = dir[{curr, c}];
        }

        int dist = sqrt((y*y) + (x*x));
        if((curr == 'N' and dist == 0) or curr != 'N') return 1;
        return 0;
    }
};
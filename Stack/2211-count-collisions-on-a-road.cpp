class Solution {
public:
    int countCollisions(string directions) {
    
    auto canCollide = [](char &x, char &y) {
        if(x == 'R' and y == 'L') return 2;
        else if(x == 'S' and y == 'L') return 1;
        else if(x == 'R' and y == 'S') return 1;
        return 0;
    };

    int ans = 0;
    
    stack<char> S;
    for(auto c : directions) {
        if(S.empty() or S.top() == c) S.push(c);
        else {
            while(!S.empty()) {
                if(canCollide(S.top(), c)) {
                    ans += canCollide(S.top(), c);
                    c = 'S';
                    S.pop();
                } else break;
            }
            S.push(c);
        }

    }
    return ans;
    }
};
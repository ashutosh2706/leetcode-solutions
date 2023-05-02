class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
    
        vector<int> S;
        for(int rock : nums) {

            if(S.empty()) { 
                S.push_back(rock);
                continue;
            }
            int last = S.back();
            if(last > 0 && rock > 0 || last < 0 && rock < 0) S.push_back(rock);
            else {
                while(!S.empty() && (S.back() > 0 && rock < 0)) {
                    if(abs(S.back()) == abs(rock)) {
                        rock = 0;
                        S.pop_back();
                        break;
                    } else if(abs(S.back()) > abs(rock)) {
                        rock = 0;
                        break;
                    }else S.pop_back();
                }
                if(rock) S.push_back(rock);
            }
        }
        return S;    
    }
};
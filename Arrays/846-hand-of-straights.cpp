class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize) return 0;
        map<int,int> map;
        for(int i=0; i<hand.size(); i++) {
            map[hand[i]]++;
        }
        auto it = begin(map);
        while(it != end(map)) {
            if(it->second == 0) {
                ++it;
                continue;
            }
            int v = it->first;
            for(int x=0; x<groupSize; x++) {
                if(map[v] == 0) return 0;
                map[v]--;
                v++;
            }
        }
        return 1;
    }
};
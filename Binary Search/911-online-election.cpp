class TopVotedCandidate {
public:
   
    int max_vote = 0, person = 0;
    map<int, int> votes, map;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for(int i=0; i<persons.size(); i++) {
            if(++votes[persons[i]] >= max_vote) {
                max_vote = votes[persons[i]];
                person = persons[i];
            }
            map[times[i]] = person;
        }
    }
    
    int q(int t) {
        if(map.find(t) == map.end()) {
            auto it = map.lower_bound(t);
            return (--it)->second;
        }
        return map.lower_bound(t)->second;
    }
};
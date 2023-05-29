class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& list) {
    set<string> words;
    for(auto &s:list) words.insert(s);
    if(words.count(end)==0) return 0;
    queue<string> q;
    q.push(begin);
    int step = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            string word=q.front(); q.pop();
            if(word==end) return step+1;
            for(int ind=0; ind<word.length(); ind++) {
                char c = word[ind];
                for(char ch='a'; ch<='z'; ch++) {
                    word[ind] = ch;
                    if(words.count(word)) {
                        q.push(word);
                        words.erase(word);
                    }
                }
                word[ind]=c;
            }
        }
        step++;
    }
    return 0;
    }
};
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
    set<string> genes;
    for(auto &s:bank) genes.insert(s);
    if(genes.count(end) == 0) return -1;
    queue<string> q;
    q.push(start);
    int steps = 0;
    char nucleobase[4] = {'A','G','C','T'};
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            string gene = q.front(); q.pop();
            if(gene==end) return steps;
            for(int i=0; i<8; i++) {
                char c = gene[i];
                for(auto &a:nucleobase) {
                    gene[i] = a;
                    if(genes.count(gene)) { 
                        q.push(gene);
                        genes.erase(gene);
                    }
                }
                gene[i] = c;
            }
        }
        steps++;
    }
    return -1;
    }
};
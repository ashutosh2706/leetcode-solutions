class Solution {
private:

void fill(int start, int end, string &s, char l, char r) {
    if(start == end) {
        if(l == r) s[start] = l;
        else s[start] = '.';
        return;
    }
    if(start > end) return;

    if(l == 'L' && r == 'R') {
        s[start] = '.';
        s[end] = '.';
        fill(start+1, end-1, s, l, r);
    } else if(l == 'R' && r == 'L') {
        s[start] = 'R';
        s[end] = 'L';
        fill(start + 1, end - 1, s, l, r);
    } else if(l == r) {
        s[start] = l;
        s[end] = l;
        fill(start + 1, end - 1, s, l, r);
    }
 }

 
public:
    string pushDominoes(string s) {
    
    if(s.length() == 1) return s;
    int n = s.length();
    int i = 0;

    while(i < n) {

        if(s[i] != '.') {
            i++;
            continue;
        }
        if(i == 0 && s[i] == '.') {
            while(i < n && s[i] == '.') i++;
            if(i == n) fill(0, i-1,s, 'L', 'R');
            else fill(0, i-1, s,'L', s[i]);
        } else {
            int x = i;
            while(i < n && s[i] == '.') i++;
            if(i == n) fill(x, i-1,s, s[x-1], 'R');
            else fill(x, i-1,s, s[x-1], s[i]);
        }
    }

    return s;
    }
};
class Solution {
private:
vector<int> prime;
void SieveOfEratosthenes(int n) {
    prime.resize(n+1, 1);
    for (int p = 2; p*p <= n; p++) {
        if (prime[p]) {
            for (int i = p*p; i <= n; i += p)
                prime[i] = 0;
        }
    }
    prime[0] = prime[1] = 0;
}
public:
    vector<vector<int>> findPrimePairs(int n) {
        SieveOfEratosthenes(n);
        vector<vector<int>> res;
        for(int i=2; i<=n; i++) {
            if(i <= n-i) {
                if(prime[i] and prime[n-i]) 
                    res.push_back(vector<int>{i, n-i});
            } else break;
        }
        
        return res;
    }
};
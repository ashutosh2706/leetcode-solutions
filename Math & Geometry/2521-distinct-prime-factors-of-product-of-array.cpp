class Solution {
private:
    void SieveOfEratosthenes(int n, vector<int>& primes) {
        primes.resize(n+1,1);
        for (int p = 2; p*p <= n; p++) {
            if (primes[p]) {
                for (int i = p*p; i <= n; i += p)
                    primes[i] = 0;
            }
        }
        primes[0] = primes[1] = 0;
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> primes;
        unordered_set<int> set;
        SieveOfEratosthenes(1001, primes);
        int N = nums.size();
        for(auto&i : nums) {
            int u = floor(sqrt(i));
            for(int x=1; x<=u; x++) {
                if(i%x==0) {
                    if(primes[x]) set.insert(x);
                    if(primes[i/x]) set.insert(i/x);
                } 
            }
        }
        return (int)set.size();
    }
};
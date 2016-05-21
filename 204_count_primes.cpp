/*

204. Count Primes

Description:

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {

public:

    int countPrimes(int n) {
        
        if ( n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        // define here to avoid use sqrt() all the time
        double upper_bound = sqrt(n);    
        
        for (int i = 2; i <= upper_bound; i++)
        {
            if ( isPrime[i] )
            {
                for (int j = i * i; j < n; j+= i)
                    isPrime[j] = false;
            }
        }
        return count(isPrime.begin(),isPrime.end(),true);
    }
};

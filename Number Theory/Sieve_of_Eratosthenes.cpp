#include <iostream>
#include <vector>
using namespace std;

//Sieve of Eratosthenes
//Leetcode 204

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1,true);

        int count=0;

        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                for(int j=i*2;j<n;j=j+i){
                    isPrime[j]=false;
                }
            }
        }
       return count;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    cout << "Number of primes less than " << n << " is: "
         << sol.countPrimes(n) << endl;

    return 0;
}

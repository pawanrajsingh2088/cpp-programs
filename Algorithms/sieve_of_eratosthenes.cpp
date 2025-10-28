/**
 * The algorithm efficiently marks non-prime numbers in a boolean array, 
 * resulting in a list of all prime numbers up to n.
 * 
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Generates all prime numbers up to n using the Sieve of Eratosthenes.
 * 
 * @param n The upper limit up to which primes are to be generated.
 * @return vector<int> A list of prime numbers from 2 to n.
 */
vector<int> generatePrimes(int n) {
    // Step 1: Initialize a boolean array to mark prime numbers
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false;

    // Step 2: Start marking multiples of each prime number
    for (int p = 2; p * p <= n; p++) {
        // If p is prime, mark its multiples as non-prime
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Step 3: Collect all prime numbers
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int n;

    // Take input from the user
    cout << "Enter an upper limit to generate primes: ";
    cin >> n;

    // Generate primes using sieve
    vector<int> primes = generatePrimes(n);

    // Display all prime numbers
    cout << "Prime numbers up to " << n << " are:\n";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void SieveOfEratosthenes(int n, ofstream& outFile) {
    auto start = chrono::high_resolution_clock::now();

    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    vector<int> primes;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;

    outFile << "\nTime taken by Sieve of Eratosthenes: " << duration.count() << " seconds\n";

    for (int p : primes) {
        outFile << p << " ";
    }
}

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void SieveOfAtkin(int limit, ofstream& outFile) {
    auto start = chrono::high_resolution_clock::now();

    vector<bool> sieve(limit + 1, false);
    vector<int> primes;

    if (limit > 2) primes.push_back(2);
    if (limit > 3) primes.push_back(3);

    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] = !sieve[n];

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7) sieve[n] = !sieve[n];

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11) sieve[n] = !sieve[n];
        }
    }

    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i <= limit; i += r * r) sieve[i] = false;
        }
    }

    for (int a = 5; a <= limit; a++) {
        if (sieve[a]) primes.push_back(a);
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;

    outFile << "\nTime taken by Sieve of Atkin: " << duration.count() << " seconds\n";

    for (int prime : primes) {
        outFile << prime << " ";
    }
}

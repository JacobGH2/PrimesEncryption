#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void SieveOfSundaram(int n, ofstream& outFile) {
    auto start = chrono::high_resolution_clock::now();

    int nNew = (n - 1) / 2;
    vector<bool> marked(nNew + 1, false);
    vector<int> primes;

    for (int i = 1; i <= nNew; i++)
        for (int j = i; (i + j + 2 * i * j) <= nNew; j++)
            marked[i + j + 2 * i * j] = true;

    if (n > 2) primes.push_back(2);

    for (int i = 1; i <= nNew; i++)
        if (!marked[i])
            primes.push_back(2 * i + 1);

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;

    outFile << "\nTime taken by Sieve of Sundaram: " << duration.count() << " seconds\n";

    for (int prime : primes) {
        outFile << prime << " ";
    }
}

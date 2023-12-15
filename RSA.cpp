#include <numeric>
#include <iostream>
#include <math.h>
#include <gmp.h>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main() {
    auto start = high_resolution_clock::now();
    // generate two primes -- right now they are hard-coded
    mpz_t p, q, n, car, e, d, m, c;

    mpz_init_set_str(p, "31477", 10);
    mpz_init_set_str(q, "58831", 10);

    cout << "using primes: ";
    mpz_out_str(NULL, 10, p);
    cout << " ";
    mpz_out_str(NULL, 10, q);
    cout << endl;

    // compute n
    mpz_init(n);
    mpz_mul(n, p, q);
    cout << "n: ";
    mpz_out_str(NULL, 10, n);
    cout << endl;

    // Carmichael totient
    mpz_t pMinus, qMinus;
    mpz_sub_ui(pMinus, p, 1);
    mpz_sub_ui(qMinus, q, 1);
    mpz_init(car);
    mpz_lcm(car, pMinus, qMinus);
    cout << "car: ";
    mpz_out_str(NULL, 10, car);
    cout << endl;

    // find suitable e value
    mpz_t maxPrime;
    mpz_init(maxPrime);
    if (mpz_cmp(p, q)) {
        mpz_set(maxPrime, p);
    } else {
        mpz_set(maxPrime, q);
    }
 
    mpz_init(e);
    mpz_nextprime(e, maxPrime);
    cout << "e: ";
    mpz_out_str(NULL, 10, e);
    cout << endl;

    // modular multiplicative inverse of e (mod car)
    mpz_init(d);
    mpz_invert(d, e, car);
    cout << "d: ";
    mpz_out_str(NULL, 10, d);
    cout << endl;

    // enter message -- must be less than n
    mpz_init_set_str(m, "397744444", 10);

    // encrypt message m, store resulting cyphertext in c
    mpz_init(c);
    mpz_powm(c, m, e, n);

    // decrypt c
    mpz_t result;
    mpz_init(result);
    mpz_powm(result, c, d, n);

    cout << "Message \"";
    mpz_out_str(NULL, 10, m);
    cout << "\" is encoded as \"";
    mpz_out_str(NULL, 10, c);
    cout << "\" then decrypted to \"";
    mpz_out_str(NULL, 10, result);
    cout << "\"" << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Running time: " << duration.count() << " microseconds" << endl;
    return 0;
}
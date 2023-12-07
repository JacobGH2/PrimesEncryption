#include <fstream>
#include "sieve_of_erat.cpp"
#include "sieve_of_atkin.cpp"
#include "sieve_of_sund.cpp"

using namespace std;

int main() {
    int n = 60000;

    ofstream outFileEratosthenes("output_eratosthenes.txt");
    ofstream outFileSundaram("output_sundaram.txt");
    ofstream outFileAtkin("output_atkin.txt");

    SieveOfEratosthenes(n, outFileEratosthenes);
    SieveOfSundaram(n, outFileSundaram);
    SieveOfAtkin(n, outFileAtkin);

    outFileEratosthenes.close();
    outFileSundaram.close();
    outFileAtkin.close();

    return 0;
}

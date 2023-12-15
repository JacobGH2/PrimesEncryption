rsa: RSA.cpp
	g++ RSA.cpp -lgmpxx -lgmp -std=c++11 -o RSA
	./RSA

main: main.cpp sieve_of_atkin.cpp sieve_of_erat.cpp sieve_of_sund.cpp
	g++ main.cpp -std=c++11 -o main
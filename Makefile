all: RSA.cpp
	g++ RSA.cpp -lgmpxx -lgmp -std=c++11 -o RSA
	./RSA
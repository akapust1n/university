#ifndef ENIGMA_H
#define ENIGMA_H
#include <array>
#include <string>
#include <vector>
class RSA {

public:
    RSA();
    void encrypt(const std::string& filename);
    void decrypt(const std::string& filename);

private:
    int sundaram(int n);
    int gcd(int a, int b);

private:
    unsigned int e;
    int d;
    unsigned int n;
};

#endif // ENIGMA_H

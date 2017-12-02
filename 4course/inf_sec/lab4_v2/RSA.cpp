#include "RSA.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

RSA::RSA()
{
    e = 0;
    d = 0;
    srand((unsigned)time(NULL));

    int p_simple = 19;
    int q_simple = 31;

    n = p_simple * q_simple;
    // Генерация числа d и проверка его на взаимопростоту
    // с числом ((p_simple-1)*(q_simple-1)).
    int d_simple = 0;
    int m = (p_simple - 1) * (q_simple - 1);

    //нахождение взаимно простного числа
    while (d_simple != 1) {
        d = rand() % 100 + 2;
        d_simple = gcd(d, m);
    }

    //Определение числа e, для которого является истинным
    //соотношение (e*d)%((p_simple-1)*(q_simple-1))=1.
    unsigned int e_simple = 0;
    while (e_simple != 1) {
        e += 1;
        e_simple = (e * d) % m;
    }
}

void RSA::encrypt(const std::string& filename)
{
    char ch;

    std::ifstream file(filename, std::ios::binary);
    std::ofstream fileEncrypted("encrypted_" + filename, std::ios::binary);
    std::vector<uint8_t> start;
    while (file.read(reinterpret_cast<char*>(&ch), sizeof(ch))) {
        start.push_back(ch);
    }

    std::vector<int> result;
    int c;
    for (int j = 0; j < start.size(); j++) {
        c = 1;
        unsigned int i = 0;
        int ASCIIcode = static_cast<int>(start[j]);
        if (start[j] < 0)
            std::cout << "zero !!\n";
        while (i < e) {
            c = c * ASCIIcode;
            c = c % n;
            i++;
        }

        result.push_back(c);
    }

    for (auto byte : result) {
        fileEncrypted.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
    }
    fileEncrypted.close();
    file.close();
}

void RSA::decrypt(const std::string& filename)
{
    std::ifstream fileEncrypted(filename, std::ios::binary);
    std::ofstream fileDecrypted("dec_" + filename, std::ios::binary);

    std::vector<int> start;
    int ch;
    while (fileEncrypted.read(reinterpret_cast<char*>(&ch), sizeof(ch))) {
        start.push_back(ch);
    }

    std::vector<uint8_t> result;
    int m;
    for (int j = 0; j < start.size(); j++) {
        unsigned int i = 0;
        m = 1;
        while (i < d) {
            m = m * static_cast<int>(start[j]);
            m = m % n;
            i++;
        }
        if (m > 255)
            std::cout << "loss!!\n";
        result.push_back(m);
    }

    for (auto byte : result) {
        fileDecrypted << byte;
    }
    fileEncrypted.close();
    fileDecrypted.close();
}

//Алгоритм "решето Сундарама". Выбирает все простые числа
//до заданного (случайно сгенерированного).
int RSA::sundaram(int n)
{
    int *a = new int[n], i, j, k;
    memset(a, 0, sizeof(int) * n);
    for (i = 1; 3 * i + 1 < n; i++) {
        for (j = 1; (k = i + j + 2 * i * j) < n && j <= i; j++)
            a[k] = 1;
    }
    //Выбирает из списка простых чисел ближайшее к заданному.
    for (i = n - 1; i >= 1; i--)
        if (a[i] == 0) {
            return (2 * i + 1);
            break;
        }
    delete[] a;
}

//Алгоритм Евклида. Алгоритм для нахождения наибольшего
//общего делителя двух целых чисел.
int RSA::gcd(int a, int b)
{
    while (a != 0 && b != 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;
    return abs(a + b);
}

#include "AES.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

// Расписание ключей
AES::AES()
{
    for (int i = 0; i < 16; i++) { //128key
        c.key.push_back(rand() % 100);
    };

    c.rounds = 10;
    int nk = 16 / 4;
    std::vector<uint8_t> xKey(16 * 11); //

    int i = 0;
    for (; i < nk; i++) {
        xKey[(4 * i) + 0] = c.key[(4 * i) + 0];
        xKey[(4 * i) + 1] = c.key[(4 * i) + 1];
        xKey[(4 * i) + 2] = c.key[(4 * i) + 2];
        xKey[(4 * i) + 3] = c.key[(4 * i) + 3];
    }
    std::vector<uint8_t> temp(4); //
    for (; i < xKey.size() / 4; i++) {
        temp[0] = xKey[4 * (i - 1) + 0];
        temp[1] = xKey[4 * (i - 1) + 1];
        temp[2] = xKey[4 * (i - 1) + 2];
        temp[3] = xKey[4 * (i - 1) + 3];

        if (i % nk == 0) {
            rotw(temp);
            replaceBytes(temp);
            temp[0] = temp[0] ^ getRcon(i / nk);
        }
        xKey[(4 * i) + 0] = xKey[4 * (i - nk) + 0] ^ temp[0];
        xKey[(4 * i) + 1] = xKey[4 * (i - nk) + 1] ^ temp[1];
        xKey[(4 * i) + 2] = xKey[4 * (i - nk) + 2] ^ temp[2];
        xKey[(4 * i) + 3] = xKey[4 * (i - nk) + 3] ^ temp[3];
    }
    c.xkey = xKey;
}

void AES::encrypt(const std::string& filename)
{
    char ch;

    std::ifstream file(filename, std::ios::binary);
    std::ofstream fileEncrypted("encrypted_" + filename, std::ios::binary);
    std::vector<uint8_t> b;
    while (file.read(&ch, sizeof(ch))) {
        b.push_back(ch);
    }

    int length = b.size();
    if (length % 16 != 0) {
        length = 16 * (b.size() / 16 + 1);
    }
    std::vector<uint8_t> result;
    for (int i = 0; i < length / 16; i++) {
        std::vector<uint8_t> temp(b.begin() + 16 * i, b.begin() + (16 * (i + 1)));
        encryptBlock(temp);
        result.insert(result.end(), temp.begin(), temp.end());
    }

    for (auto byte : result) {
        fileEncrypted << byte;
    }
    fileEncrypted.close();
    file.close();
}

void AES::decrypt(const std::string& filename)
{
    std::ifstream fileEncrypted(filename, std::ios::binary);
    std::ofstream fileDecrypted("dec_" + filename, std::ios::binary);

    std::vector<uint8_t> b;
    char ch;
    while (fileEncrypted.read(&ch, sizeof(ch))) {
        b.push_back(ch);
    }

    std::vector<uint8_t> result;
    for (int i = 0; i < b.size() / 16; i++) {
        std::vector<uint8_t> temp(b.begin() + 16 * i, b.begin() + (16 * (i + 1)));
        decryptBlock(temp);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    removePadding(result);
    for (auto byte : result) {
        fileDecrypted << byte;
    }
    fileEncrypted.close();
    fileDecrypted.close();
}

void AES::encryptBlock(std::vector<uint8_t>& s)
{
    addRoundKey(s, c.xkey);
    for (int i = 1; i < c.rounds; i++) {
        replaceBytes(s);
        shiftRows(s);
        mixColumns(s);
        std::vector<uint8_t> temp(c.xkey.begin() + i * 16, c.xkey.end());
        addRoundKey(s, temp);
    }

    replaceBytes(s);
    shiftRows(s);
    std::vector<uint8_t> temp(c.xkey.begin() + (c.xkey.size() - 16), c.xkey.end());

    addRoundKey(s, temp);
}

void AES::rotw(std::vector<uint8_t>& w)
{
    auto temp = w[0];
    w[0] = w[1];
    w[1] = w[2];
    w[2] = w[3];
    w[3] = temp;
}

// Замена байтов по таблице
void AES::replaceBytes(std::vector<uint8_t>& s)
{
    for (int i = 0; i < s.size(); i++) {
        s[i] = getSboxSub(s[i]);
    }
}

uint8_t AES::getSboxSub(uint8_t b)
{
    return sbox[b];
}

uint8_t AES::getRcon(int round)
{
    return rcon_const[round - 1];
}

// Сдвиг строки
void AES::shiftRows(std::vector<uint8_t>& s)
{
    std::vector<uint8_t> t(4);
    for (int i = 0; i < 4; i++) {
        t[0] = s[5 * i];
        t[1] = s[((5 * i) + 4) % 16];
        t[2] = s[((5 * i) + 8) % 16];
        t[3] = s[((5 * i) + 12) % 16];

        s[i] = t[0];
        s[i + 4] = t[1];
        s[i + 8] = t[2];
        s[i + 12] = t[3];
    };
}
// Умножение столбцов
void AES::mixColumns(std::vector<uint8_t>& s)
{
    std::vector<uint8_t> a(4);

    for (int i = 0; i < 4; i++) {
        a[0] = s[(4 * i) + 0];
        a[1] = s[(4 * i) + 1];
        a[2] = s[(4 * i) + 2];
        a[3] = s[(4 * i) + 3];

        s[(4 * i) + 0]
            = galuaMul(0x02, a[0]) ^ galuaMul(0x03, a[1]) ^ a[2] ^ a[3]; // 2*a0 + 3*a1 + a2 + a3
        s[(4 * i) + 1]
            = galuaMul(0x02, a[1]) ^ galuaMul(0x03, a[2]) ^ a[3] ^ a[0]; // 2*a1 + 3*a2 + a3 + a0
        s[(4 * i) + 2]
            = galuaMul(0x02, a[2]) ^ galuaMul(0x03, a[3]) ^ a[0] ^ a[1]; // 2*a2 + 3*a3 + a0 + a1
        s[(4 * i) + 3]
            = galuaMul(0x02, a[3]) ^ galuaMul(0x03, a[0]) ^ a[1] ^ a[2]; // 2*a3 + 3*a0 + a1 + a2
    }
}

// Умножение двух байтов в поле GF(2^8)
uint8_t AES::galuaMul(uint8_t a, uint8_t b)
{
    uint8_t result = 0;
    uint8_t h;
    for (int i = 0; i < 8; i++) {
        if ((b & 0x01) != 0) {
            result ^= a;
        }
        h = a >> 7;
        a <<= 1;
        if (h != 0) {
            a ^= 0x1B;
        }
        b >>= 1;
    };
    return result;
}

// добавляет (xor) к состоянию ключа текущего раунда
void AES::addRoundKey(std::vector<uint8_t>& s, std::vector<uint8_t>& w)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = s[i] ^ w[i];
}

// Инверсированное сдвиг
void AES::shiftRowsInv(std::vector<uint8_t>& s)
{
    std::vector<uint8_t> t(4);
    for (int i = 0; i < 4; i++) {
        t[0] = s[(16 - (3 * i)) % 16];
        t[1] = s[(20 - (3 * i)) % 16];
        t[2] = s[(24 - (3 * i)) % 16];
        t[3] = s[12 - (3 * i)];

        s[i] = t[0];
        s[i + 4] = t[1];
        s[i + 8] = t[2];
        s[i + 12] = t[3];
    }
}

void AES::decryptBlock(std::vector<uint8_t>& s)
{
    std::vector<uint8_t> temp(c.xkey.end() - 16, c.xkey.end());
    addRoundKey(s, temp);
    for (int i = 1; i < c.rounds; i++) {
        shiftRowsInv(s);
        subBytesInv(s);
        std::vector<uint8_t> temp(c.xkey.end() - ((i + 1) * 16), c.xkey.end());

        addRoundKey(s, temp);
        mixColumnsInv(s);
    }

    shiftRowsInv(s);
    subBytesInv(s);
    addRoundKey(s, c.xkey);
}

void AES::subBytesInv(std::vector<uint8_t>& s)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = getInvSboxSub(s[i]);
}

// Инверсированное умножение столбцов
void AES::mixColumnsInv(std::vector<uint8_t>& s)
{
    std::vector<uint8_t> a(4);
    for (int i = 0; i < 4; i++) {
        a[0] = s[(4 * i) + 0];
        a[1] = s[(4 * i) + 1];
        a[2] = s[(4 * i) + 2];
        a[3] = s[(4 * i) + 3];

        s[(4 * i) + 0] = galuaMul(0x0E, a[0]) ^ galuaMul(0x0B, a[1]) ^ galuaMul(0x0D, a[2]) ^ galuaMul(0x09, a[3]); /* 14*a0 + 11*a1 + 13*a2 + 9*a3 */
        s[(4 * i) + 1] = galuaMul(0x0E, a[1]) ^ galuaMul(0x0B, a[2]) ^ galuaMul(0x0D, a[3]) ^ galuaMul(0x09, a[0]); /* 14*a1 + 11*a2 + 13*a3 + 9*a0 */
        s[(4 * i) + 2] = galuaMul(0x0E, a[2]) ^ galuaMul(0x0B, a[3]) ^ galuaMul(0x0D, a[0]) ^ galuaMul(0x09, a[1]); /* 14*a2 + 11*a3 + 13*a0 + 9*a1 */
        s[(4 * i) + 3] = galuaMul(0x0E, a[3]) ^ galuaMul(0x0B, a[0]) ^ galuaMul(0x0D, a[1]) ^ galuaMul(0x09, a[2]); /* 14*a3 + 11*a0 + 13*a1 + 9*a2 */
    }
}

void AES::removePadding(std::vector<uint8_t>& b)
{
    int idx = 0;
    for (int i = b.size() - 1; i >= 0; i--) {
        if (b[i] != 0x00) {
            idx = i + 1;
            break;
        }
    }
    b.erase(b.begin() + idx, b.end());
}

uint8_t AES::getInvSboxSub(uint8_t b)
{
    return rsbox[b];
}

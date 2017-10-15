#ifndef ENIGMA_H
#define ENIGMA_H
#include <array>
#include <string>
//codes of rotors http://www.codesandciphers.org.uk/enigma/rotorspec.htm
class Enigma {
public:
    Enigma(char rotor1, char rotor2, char rotor3);
    void encrypt(const std::string& filename);

private:
    bool isLetter(char code);
    char getByte(char letter);
    char encryptLetter(char letter);
    char rotorRoll(char letter);
    char sumMod26(char rotor, char letter);
    char diffMod26(char rotor, char letter);
    char getRotorLetter(auto &rotorMap, char pos);
    char reversePosition(auto &rotorMap, char letter);

private:
    char m_lRotor, m_mRotor, m_rRotor;
    char m_mRollPos, m_lRollPos, m_rRollPos;
    static constexpr std::array<char, 26> m_lRotorMap = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
    static constexpr std::array<char, 26> m_mRotorMap = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
    static constexpr std::array<char, 26> m_rRotorMap = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
    static constexpr std::array<char, 26> representation = { 24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4,
        1, 5, 25, 2, 22, 21, 9, 0, 19 }; // (AY) (BR) (CU) (DH) (EQ) (FS) (GL) (IP) (JX) (KN) (MO) (TZ) (VW)
    //m_mRotorMap,m_lRotorMap;
};

#endif // ENIGMA_H

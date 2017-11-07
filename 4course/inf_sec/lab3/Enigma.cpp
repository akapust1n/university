#include "Enigma.h"
#include <algorithm>
#include <fstream>
#include <iostream>
constexpr std::array<char, 26> Enigma::m_rRotorMap, Enigma::m_mRotorMap, Enigma::m_lRotorMap, Enigma::representation;

Enigma::Enigma(char rotor1, char rotor2, char rotor3)

{
    m_lRotor = toupper(rotor1) - 'A';
    m_mRotor = toupper(rotor2) - 'A';
    m_rRotor = toupper(rotor3) - 'A';
    m_lRollPos = 17;
    m_mRollPos = 5;
    m_rRollPos = 22;
}

void Enigma::encrypt(const std::string& filename)
{
    char ch;

    std::ifstream file(filename, std::ios::binary);
    std::ofstream fileEncrypted("encrypted_" + filename, std::ios::binary);
    while (file.read(&ch, sizeof(ch))) {
        char dd = getByte(ch);
        fileEncrypted << dd;
    }
    file.close();
    fileEncrypted.close();
}

bool Enigma::isLetter(char code)
{
    return (code >= 'a' and code <= 'z' or code >= 'A' and code <= 'Z');
}

char Enigma::getByte(char letter)
{
    return isLetter(letter) ? (encryptLetter(letter)) : letter;
}

char Enigma::encryptLetter(char letter)
{
    bool isUpper = true;
    if (letter > 'Z') {
        isUpper = false;
    }
    letter = toupper(letter) - 'A';
    m_rRotor = rotorRoll(m_rRotor);
    if (m_rRotor == m_rRollPos) {
        m_mRotor = rotorRoll(m_mRotor);
        if (m_mRotor == m_mRollPos) {
            m_lRotor = rotorRoll(m_lRotor);
        }
    }
    letter = sumMod26(m_rRotor, letter);
    letter = getRotorLetter(m_rRotorMap, letter);
    letter = sumMod26(letter, diffMod26(m_mRotor, m_rRotor));
    letter = getRotorLetter(m_mRotorMap, letter);
    letter = sumMod26(letter, diffMod26(m_lRotor, m_mRotor));
    letter = getRotorLetter(m_lRotorMap, letter);
    letter = diffMod26(letter, m_lRotor);

    letter = representation[letter];
    letter = sumMod26(letter, m_lRotor);
    letter = reversePosition(m_lRotorMap, letter);

    letter = diffMod26(letter, diffMod26(m_lRotor, m_mRotor));
    letter = reversePosition(m_mRotorMap, letter);
    letter = diffMod26(letter, diffMod26(m_mRotor, m_rRotor));
    letter = reversePosition(m_rRotorMap, letter);
    letter = diffMod26(letter, m_rRotor);

    if (isUpper) {
        letter += 'A';
    } else {
        letter += 'a';
    }
    return letter;
}

char Enigma::rotorRoll(char letter)
{
    return ((letter + 1) % 26);
}

char Enigma::sumMod26(char rotor, char letter)
{
    return ((rotor + letter) % 26);
}

char Enigma::diffMod26(char rotor, char letter)
{
    int diff = ((rotor - letter) % 26);
    if(diff<0) {diff+=26;}
    return diff;
}

char Enigma::getRotorLetter(auto& rotorMap, char pos)
{
    return rotorMap[pos] - 'A';
}

char Enigma::reversePosition(auto& rotorMap, char letter)
{
    letter += 'A';
    return std::distance(&rotorMap[0], std::find(&rotorMap[0], &rotorMap[25], letter));
}

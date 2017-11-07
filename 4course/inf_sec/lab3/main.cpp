#include <Enigma.h>
#include <iostream>
#include <math.h>
#include <string>

int main(int argc, char* argv[])
{
    char rotor1, rotor2, rotor3;
    if (argc < 2) {
        std::cerr << "enter args!\n";
        std::cout << "Usage: ./lab2 filename mode 1rot_start_pos 2rot_start_pos 3rot_start_pos\n";
        return -1;
    }
    if (argc < 6) {
        rotor1 = 'C';
        rotor2 = 'B';
        rotor3 = 'A';
    } else {
        rotor1 = static_cast<char>(toupper(argv[2][0])); //верим, что юзер введет правильные буквы
        rotor2 = static_cast<char>(toupper(argv[3][0]));
        rotor3 = static_cast<char>(toupper(argv[4][0]));
    }
    std::string filename(argv[1]);
    Enigma enigma(rotor1, rotor2, rotor3);

    enigma.encrypt(filename);


    return 0;
}

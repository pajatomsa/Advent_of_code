#include <fstream>
#include <iostream>
#include <string>

int rotationPassword();

int main() {
    int zeros = rotationPassword();
    std::cout << zeros << std::endl;
}

int rotationPassword() {
    int zeros = 0;
    int rotations = 50;
    char direction;
    int number;
    int passedZeros = 0;

    std::ifstream soubor("L25.txt");
    std::string radek;

    if (soubor.is_open()) {
        while (std::getline(soubor, radek)) {
            if (radek.empty()) continue;
            direction = radek[0];
            number = std::stoi(radek.substr(1));
            if (direction == 'L') {
                if ((rotations - number) <= 0) {
                    for (int i = 0; i < ((rotations - number) / 100 ) * (-1); i++)
                    {
                        passedZeros = passedZeros + ((rotations - number) / 100 ) * (-1) + 1;
                    }
                    
                }
                
                rotations = (rotations - number) % 100;

                if (rotations < 0) {
                    rotations = rotations + 100;
                }
            }
            if (direction == 'R') {
                if ((rotations + number) >= 100) {
                    for (int i = 0; i < (rotations + number) / 100; i++)
                    {
                        passedZeros++;
                    }
                }

                rotations = (rotations + number) % 100;
            }

            if (rotations == 0) {
                zeros++;
            }
        }
    }
    std::cout << passedZeros << std::endl;
    soubor.close();
    return zeros;
}
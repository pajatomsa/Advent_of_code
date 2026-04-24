#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
long long invalidId();

int main() {
    long long addInvalid = invalidId();
    std::cout << addInvalid;
    return 0;
}

long long invalidId() {
    std::ifstream soubor("invalid_id.txt");
    std::string radek;
    std::string range;
    long long addInvalid = 0;
    if (soubor.is_open()) {
        std::getline(soubor, radek);
        std::stringstream ss(radek);
        while (std::getline(ss, radek, ',')) {

            long long startId = std::stoll(radek.substr(0, radek.find('-')));
            long long endId = std::stoll(radek.substr(radek.find('-') + 1, radek.npos));

            for (long long i = startId; i <= endId; i++) {
                std::string number = std::to_string(i);
                size_t half = number.length() / 2;

                if (number.length() % 2 != 0) {
                    continue;
                }

                std::string firstHalf = number.substr(0, (half));
                std::string secondHalf = number.substr(half);

                if (firstHalf == secondHalf) {
                    addInvalid += i;
                }
            }
        }
    }
    return addInvalid;
}
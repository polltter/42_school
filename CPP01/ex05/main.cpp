#include "Harl.hpp"

int main() {
    std::string str;
    Harl        h;
    while (std::getline(std::cin, str)) {
        h.comlain(str);
    }
    return 0;
}

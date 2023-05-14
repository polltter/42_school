#include "Zombie.hpp"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main() {
    randomChump("Miguel");
    Zombie *b = newZombie("Edu");
    b->announce();
    delete b;
    return 0;
}

#include "Zombie.h++"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main() {
    randomChump("gay");
    Zombie *b = newZombie("homo");
    b->announce();
    delete b;
    return 0;
}

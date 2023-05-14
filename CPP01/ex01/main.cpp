#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
    int N = 10;
    Zombie *a = zombieHorde(N, "Ezequiel");

    for (int i = 0; i < N; i++) {
        a[i].announce();
    }
    delete[] a;
    return 0;
}

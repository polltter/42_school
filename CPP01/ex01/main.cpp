#include "Zombie.h++"

Zombie* zombieHorde( int N, std::string name );

int main() {
    int N = 10;
    Zombie *a = zombieHorde(N, "gay");

    for (int i = 0; i < N; i++) {
        a[i].announce();
    }
    delete[] a;
    return 0;
}

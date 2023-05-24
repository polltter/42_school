#include "ClapTrap.hpp"

int main() {
    ClapTrap Ze("Jose Consciencia");
    ClapTrap Migas("Miguel Leao");

    std::cout << Migas << std::endl;
    std::cout << Ze << std::endl;

    std::cout << std::endl;

    Migas.attack("Jose Consciencia");
    Ze.takeDamage(Migas.getAttackDamage());
    std::cout << Migas << std::endl;
    std::cout << Ze << std::endl;

    std::cout << std::endl;

    Ze.setAttackDamage(2);
    Ze.attack("Miguel Leao");
    Migas.takeDamage(Ze.getAttackDamage());
    std::cout << Migas << std::endl;
    std::cout << Ze << std::endl;

    std::cout << std::endl;

    Migas.beRepaired(100);
    Migas.setAttackDamage(1000000);
    Migas.attack("Jose Consciencia");
    Ze.takeDamage(Migas.getAttackDamage());
    return 0;
}

#include "FragTrap.hpp"

int main() {
    FragTrap Ze("Jose Consciencia");
    FragTrap Migas("Miguel Leao");
    FragTrap Oscar(Migas);

    Oscar.setName("Oscaralho");

    std::cout << std::endl;

    Migas.attack("Jose Consciencia");
    Ze.takeDamage(Migas.getAttackDamage());

    std::cout << std::endl;

    Ze.setAttackDamage(2);
    Ze.attack("Miguel Leao");
    Migas.takeDamage(Ze.getAttackDamage());

    std::cout << std::endl;

    Migas.beRepaired(100);
    Migas.setAttackDamage(1000000);
    Migas.attack("Jose Consciencia");
    Ze.takeDamage(Migas.getAttackDamage());

    std::cout << std::endl;

    Oscar.highFivesGuys();

    std::cout << std::endl;

    return 0;
}

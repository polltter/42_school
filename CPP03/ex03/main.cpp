#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int	main(void)
{
    std::string	One = "One";
    std::string	Two = "Two";

    DiamondTrap	D1(One);
    DiamondTrap	D2(Two);

    D1.whoAmI();
    D2.whoAmI();

    std::cout << "I am " << D1.getName() << " and my hit points as a DiamondTrap are " << D1.getHitPoints() << std::endl;
    std::cout << "I am " << D1.getName() << " and my energy points as a DiamondTrap are " << D1.getEnergyPoints() << std::endl;
    std::cout << "I am " << D1.getName() << " and my damage points as a DiamondTrap are " << D1.getAttackDamage() << std::endl << std::endl;

    std::cout << "Now for the interesting part:" << std::endl;
    D1.attack(Two);
    D2.takeDamage(D1.getAttackDamage());
    D2.attack(One);
    D1.takeDamage(D2.getAttackDamage());
    D2.beRepaired(15);
    D1.attack(Two);
    D2.takeDamage(D1.getAttackDamage());

    std::cout << std::endl;

    D1.guardGate();
    D1.highFivesGuys();

    std::cout << std::endl;

    D1.attack(Two);
    D2.takeDamage(D1.getAttackDamage());
    D1.attack(Two);
    D2.takeDamage(D1.getAttackDamage());
    D2.beRepaired(15);
}

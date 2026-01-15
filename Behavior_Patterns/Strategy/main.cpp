#include "Strategy.hpp"
#include <iostream>

int main(int argc , const char *argv[])
{
    User* character = new User;
    AK47* ak = new AK47;
    Knife* knife = new Knife;

    character->setStrategy(ak);
    character->useStrategy();
    character->setStrategy(knife);
    character->useStrategy();

    delete character;
    delete ak;
    delete knife;

    std::cout << "Test over!!!" << std::endl;
    
    return 0;
}
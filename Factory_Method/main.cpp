#include "Factory_Method.hpp"

int main(int argc , const char *argv[])
{
    Creator* creatorA = new ConcreateCreatrorA();
    Product* productA = creatorA->factoryMethod();
    productA->operation();
    
    Creator* creatorB = new ConcreateCreatorB();
    Product* productB = creatorB->factoryMethod();
    productB->operation();

    delete creatorA;
    delete creatorB;
    delete productA;
    delete productB;

    return 0;
}
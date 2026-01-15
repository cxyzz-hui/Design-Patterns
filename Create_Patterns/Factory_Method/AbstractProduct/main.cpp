#include "AbstractProduct.hpp"

int main(int argc , const char *argv[])
{
    AbstractFactory* factory1 = new ConcreateFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    productA1->operationA();
    productB1->operationB();

    AbstractFactory* factory2 = new ConcreateFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    productA2->operationA();
    productB2->operationB();

    delete productA1;
    delete productB1;  
    delete factory1;
    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}
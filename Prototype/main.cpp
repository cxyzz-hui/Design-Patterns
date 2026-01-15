#include "Prototype.hpp"

int main(int argc , const char *argv[])
{
    Prototype* p = new ConcreatePrototype(); 
    Prototype* p1 = p->Clone();

    return 0;
}
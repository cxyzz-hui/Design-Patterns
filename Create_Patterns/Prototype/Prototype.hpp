#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

#include <iostream>

class Prototype
{
public:
    virtual ~Prototype();
    virtual Prototype* Clone() const = 0;
protected:
    Prototype();
};

class ConcreatePrototype : public Prototype
{
public:
    ConcreatePrototype();
    ConcreatePrototype(const ConcreatePrototype& cp);
    ~ConcreatePrototype();
    Prototype* Clone() const;
};

Prototype::Prototype() 
{ 
} 
Prototype::~Prototype() 
{ 
} 
Prototype* Prototype::Clone() const 
{ 
    return 0;
} 

ConcreatePrototype::ConcreatePrototype() 
{ 

} 
ConcreatePrototype::~ConcreatePrototype() 
{ 
} 
ConcreatePrototype::ConcreatePrototype(const ConcreatePrototype& cp) 
{ 
    std::cout<<"ConcretePrototype copy ..."<<std::endl;
} 
Prototype* ConcreatePrototype::Clone() const 
{ 
    return new ConcreatePrototype(*this); 
}


#endif
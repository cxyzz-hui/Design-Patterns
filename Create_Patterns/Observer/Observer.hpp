#pragma once

#include <iostream>
#include <list>

//抽象观察者
class AbstractObserver
{
public:
    virtual void update() = 0;
};

//具体观察者A
class ObserverA : public AbstractObserver
{
public:
    ObserverA()
    {
        std::cout << "HeroA正在输出" << std::endl;
    }

    void update() override
    {
        std::cout << "HeroA在挂机"  << std::endl;
    }
};

//具体观察者B
class ObserverB : public AbstractObserver
{
public:
    ObserverB()
    {
        std::cout << "HeroB正在输出" << std::endl;
    }

    void update() override
    {
        std::cout << "HeroB在挂机"  << std::endl;
    }
};

//具体观察者C
class ObserverC : public AbstractObserver
{   
public:
    ObserverC()
    {
        std::cout << "HeroC正在输出" << std::endl;
    }

    void update() override
    {
        std::cout << "HeroC在挂机"  << std::endl;
    }
};  

//具体观察者D
class ObserverD : public AbstractObserver
{  
public:
    ObserverD()
    {
        std::cout << "HeroD正在输出" << std::endl;
    }

    void update() override
    {
        std::cout << "HeroD在挂机"  << std::endl;
    }
};  

//具体观察者E
class ObserverE : public AbstractObserver   
{   
public:
    ObserverE()
    {
        std::cout << "HeroE正在输出" << std::endl;
    }

    void update() override
    {
        std::cout << "HeroE在挂机"  << std::endl;
    }
};

//抽象目标
class AbstractSubject
{
public:
    virtual void addObserver(AbstractObserver* observer) = 0;
    virtual void removeObserver(AbstractObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};

class SubjectA : public AbstractSubject
{
public:
    void addObserver(AbstractObserver* observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(AbstractObserver* observer) override
    {
        observers.remove(observer);
    }

    void notifyObservers() override
    {
        for(auto observer : observers)
        {
            observer->update();
        }
    }

    std::list<AbstractObserver*> observers;
};
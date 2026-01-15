#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <iostream>

//抽象策略:策略基类
class Strategy
{
public:
    virtual void UseStrategy() = 0;
};

//具体策略
class Knife : public Strategy
{
public:
    virtual void UseStrategy()
    {
        std::cout << "使用匕首策略\n";
    }
};

class AK47 : public Strategy
{
public:
    virtual void UseStrategy()
    {
        std::cout << "使用AK47策略" << std::endl;
    }
};

//使用策略的人
class User
{
public:
    Strategy* str;
    void setStrategy(Strategy* temp)
    {
        str = temp;
    }

    //使用策略
    void useStrategy()
    {
        str->UseStrategy();
    }
};

#endif
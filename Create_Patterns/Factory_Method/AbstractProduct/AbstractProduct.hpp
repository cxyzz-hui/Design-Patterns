#pragma once

//抽象工厂模式:一个工厂->多个产品等级结构
/*
    麦当劳（抽象工厂） → 汉堡 + 薯条 + 可乐（配套产品）
    肯德基（抽象工厂） → 炸鸡 + 薯条 + 可乐（配套产品）
    每个店提供一整套配套产品
*/

#include <iostream>
// 抽象产品A
class AbstractProductA
{
public:
    virtual void operationA() = 0;
};

//抽象产品B
class AbstractProductB
{
public:
    virtual void operationB() = 0;
};

// 具体产品A1
class ConcreateProductA1 : public AbstractProductA
{
public:
    void operationA() override
    {
        //具体产品A1的操作实现
        std::cout << "ConcreateProductA1 operation" << std::endl;
    };
};

// 具体产品A2
class ConcreateProductA2 : public AbstractProductA
{
    void operationA() override
    {
        //具体产品A2的操作实现
        std::cout << "ConcreateProductA2 operation" << std::endl;
    }
};

class ConcreateProductB1 : public AbstractProductB
{
    void operationB() override
    {
        //具体产品B1的操作实现
        std::cout << "ConcreateProductB1 operation" << std::endl;
    }
};

class ConcreateProductB2 : public AbstractProductB
{
    void operationB() override
    {
        //具体产品B2的操作实现
        std::cout << "ConcreateProductB2 operation" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory
{
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

//具体工厂1
class ConcreateFactory1 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override
    {
        return new ConcreateProductA1();
    }

    AbstractProductB* createProductB() override
    {
        return new ConcreateProductB1();
    }
};

//具体工厂2
class ConcreateFactory2 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override
    {
        return new ConcreateProductA2();
    }

    AbstractProductB* createProductB() override
    {
        return new ConcreateProductB2();
    }
};


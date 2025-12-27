#pragma once

//一个工厂->一个产品等级结构
/*
    汉堡店（工厂） → 汉堡（产品）
    披萨店（工厂） → 披萨（产品）
    每个店只做一个产品
*/

#include <iostream>

//产品接口
class Product
{
public:
    virtual void operation() = 0;
};

//具体产品A
class ConcreateProductA : public Product
{
public:
    void operation() override
    {
        //具体产品A的操作实现
        std::cout << "ConcreateProductA operation" << std::endl;
    }
};

class ConcreateProductB : public Product
{
public:
    void operation() override
    {
        //具体产品B的操作实现
        std::cout << "ConcreateProductB operation" << std::endl;
    }
};

//抽象工厂
class Creator
{
public:
    virtual Product* factoryMethod() = 0;
};

//具体产品
class ConcreateCreatrorA : public Creator
{
public:
    Product* factoryMethod() override
    {
        return new ConcreateProductA();
    };
};

class ConcreateCreatorB : public Creator
{
public: 
    Product* factoryMethod() override
    {
        return new ConcreateProductB();
    };
};


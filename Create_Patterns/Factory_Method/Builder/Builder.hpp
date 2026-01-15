#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <iostream>
#include <string>

class Monster
{
public:
    virtual ~Monster() {}

};

//各种怪物类型
class Monster_Undead : public Monster
{

};

class Monster_Element :public  Monster
{

};

class Monster_Mechine :public  Monster
{

};

class MonsterBuilder
{
public:
    virtual ~MonsterBuilder() {}

    Monster* GetResult()
    {
        return Monster_Ptr;
    }

    //分别代表着躯干，头和四肢
    virtual void LoadTrunkModel(std::string strno) = 0;
    virtual void LoadHeadModel(std::string strno) = 0;
    virtual void LoadLimbsModel(std::string strno) = 0;

protected:

    Monster* Monster_Ptr;
};

//具体怪物构造子类
class UndeadMonsterBuilder : public MonsterBuilder
{
public:
    UndeadMonsterBuilder()
    {
        Monster_Ptr = new Monster_Undead();
    }
    
    virtual void LoadTrunkModel(std::string strno)
	{
		std::cout << "载入亡灵类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//具体要做的事情其实是委托给怪物子类来完成，委托指把本该自己实现的功能转给其他类实现
		//m_pMonster->......略

	}
	virtual void LoadHeadModel(std::string strno)
	{
		std::cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}
	virtual void LoadLimbsModel(std::string strno)
	{
		std::cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}

};

class ElementMonsterBuilder : public MonsterBuilder
{
public:
    ElementMonsterBuilder()
    {
        Monster_Ptr = new Monster_Element();
    }

    virtual void LoadTrunkModel(std::string strno)
	{
		std::cout << "载入元素类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//具体要做的事情其实是委托给怪物子类来完成，委托指把本该自己实现的功能转给其他类实现
		//m_pMonster->......略

	}
	virtual void LoadHeadModel(std::string strno)
	{
		std::cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}
	virtual void LoadLimbsModel(std::string strno)
	{
		std::cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}
};

class MechineMonsterBuilder : public MonsterBuilder
{
public:
    MechineMonsterBuilder()
    {
        Monster_Ptr = new Monster_Mechine();
    }

    virtual void LoadTrunkModel(std::string strno)
	{
		std::cout << "载入机械类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//具体要做的事情其实是委托给怪物子类来完成，委托指把本该自己实现的功能转给其他类实现
		//m_pMonster->......略

	}
	virtual void LoadHeadModel(std::string strno)
	{
		std::cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}
	virtual void LoadLimbsModel(std::string strno)
	{
		std::cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << std::endl;
		//m_pMonster->......略
	}
};

//指挥类
class MonsterCommander
{
public:
    //声明的时候记得带上要搞的指针对象
    MonsterCommander(MonsterBuilder* MonsterBuilder_Ptr)
    {
        Build_Ptr = MonsterBuilder_Ptr;
    }

    //设置新的指针
    void SetBuilder(MonsterBuilder* MonsterBuilder_Ptr)
    {
        Build_Ptr = MonsterBuilder_Ptr;
    }

    //用来组装怪物的函数
    Monster* Construct(std::string model)
    {
        Build_Ptr->LoadHeadModel(model.substr(4 , 3));
        Build_Ptr->LoadTrunkModel(model.substr(7 , 3));
        Build_Ptr->LoadLimbsModel(model.substr(10 , 3));
    
        return Build_Ptr->GetResult();
    }

private:

    MonsterBuilder* Build_Ptr;
};

#endif
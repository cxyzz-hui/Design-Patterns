#include <mutex>
#include <atomic>
#include <memory>

class Singleton
{
public:
    Singleton();

    //单例模式需要禁止拷贝构造和赋值操作
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getinstance();

    //使用引用返回，最为简单并且没有线程安全问题
    static Singleton& getinstanceRef();

private:
    static Singleton* instance;
};


Singleton& Singleton::getinstanceRef()
{
    static Singleton instance; //局部静态变量，线程安全
    return instance;
}

Singleton* Singleton::getinstance()
{
    //非线程安全
    if (instance == nullptr)
    {
        instance = new Singleton();
    }
    return instance;
}

Singleton* Singleton::getinstance()
{
    std::mutex mtx;
    //双重检查锁定版本
    if(instance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if(instance == nullptr)
        {
            instance = new Singleton();
        }
    }
}


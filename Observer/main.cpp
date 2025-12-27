#include "Observer.hpp"

int main()
{
    //创建观察者对象
    ObserverA* observerA =  new ObserverA();
    ObserverB* observerB =  new ObserverB();
    ObserverC* observerC =  new ObserverC();
    ObserverD* observerD =  new ObserverD();

    //创建观察目标对象
    AbstractSubject* subject = new SubjectA();

    //注册观察者
    subject->addObserver(observerA);
    subject->addObserver(observerB);
    subject->addObserver(observerC);
    subject->addObserver(observerD);

    //目标对象状态发生变化，通知所有注册的观察者
    subject->notifyObservers();

    //删除观察者对象
    delete observerA;
    delete observerB;
    delete observerC;
    delete observerD;

    //删除目标对象
    delete subject;

    return 0;
}
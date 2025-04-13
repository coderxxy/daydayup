
#include <iostream>
#include <string>
using namespace std;

class AbstractDrinking
{
private:
    /* data */
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
    // TODO: AbstractDrinking.cpp:62:5: warning: delete called on 'AbstractDrinking' that is abstract but has non-virtual destructor
    // 上述告警在使用arm编译器编译的时候报出，意思是缺少虚的析构函数，在delete被调用的时候，会造成问题。典型的就是内存泄漏。
    // 析构函数
    virtual ~AbstractDrinking(){

    }
};

class Coffee : public AbstractDrinking
{
    public:
    virtual void Boil(){
        cout <<"煮水"<<endl;
    }
    virtual void Brew() {
        cout <<"冲泡咖啡"<<endl;
    }
    virtual void PourInCup() {
        cout <<"倒入杯中"<<endl;
    }
    virtual void PutSomething() {
        cout <<"加入糖和牛奶"<<endl;
    }
    ~Coffee(){

    }
};

class Tea : public AbstractDrinking
{
    public:
    virtual void Boil(){
        cout <<"煮水"<<endl;
    }
    virtual void Brew() {
        cout <<"冲泡茶叶"<<endl;
    }
    virtual void PourInCup() {
        cout <<"倒入杯中"<<endl;
    }
    virtual void PutSomething() {
        cout <<"加入菊花"<<endl;
    }
    ~Tea(){

    }
};


void doWork (AbstractDrinking * abs)
{
    abs->makeDrink();
    delete abs; // 释放
    abs = nullptr;
}

void testDrinking()
{
    Coffee *coff = new Coffee;
    doWork(coff);

    Tea *tea = new Tea;
    doWork(tea);
}

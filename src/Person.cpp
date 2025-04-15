#include "Person.h"


Person::Person()
{
    cout << "无参构造函数" << endl;
}
Person::~Person()
{
    // 将堆区开辟数据做释放操作
    if (m_height != NULL)
    {
        delete m_height;
        m_height = NULL;
    }
    cout << "析构函数" << endl;
}

Person::Person(int age)
{
    cout << "有参构造函数" << endl;
    m_age = age;
}

Person::Person(string nameChar, int age){
    name = nameChar;
    m_age = age;
}

Person::Person(int age, int height)
{
    cout << "有参构造函数" << endl;
    m_age = age;
    m_height = new int (height);
}
// TODO: this 解决名称冲突
Person::Person(string name)
{
    this->name = name;
}

Person::Person(const Person &p)
{
    cout<<"Person 拷贝构造函数的调用"<<endl;
    m_age = p.m_age;
    // m_height = p.m_height; // 编译器默认实现代码
    // 深拷贝
    m_height = new int(*p.m_height);
}

// TODO: 成员函数 后加const,修饰的是 this指针，让指针指向的值也不可以修改
void Person::showPersonInfo () const
{
    // m_age = 18;
    // this = NULL; // MARK: 指针不可以修改指针的指向
}

// TODO: 类和对象测试函数
void personTestHandle1 ()
{
    Person p1(23);
    cout<<"p1 age:"<<p1.m_age <<endl;

    Person p2(p1);
    cout<<"p2 age:"<<p1.m_age <<endl;
}

void personTestHandle2 ()
{
    Person p1(23, 180);
    cout<<"p1 age:"<<p1.m_age<<"\t"<<"p1 height:"<< *p1.m_height <<endl;

    Person p2(p1);
    cout<<"p2 age:"<<p1.m_age<<"\t"<<"p2 height:"<< *p1.m_height <<endl;
}

void personTestHandle3 ()
{
    
}


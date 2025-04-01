#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    /* data */
public:
    // 默认提供的无参构造函数
    Person(/* args */);
    // 默认提供的析构函数
    ~Person();
    // 自定义构造函数
    Person(int age);
    Person(int age, int height);
    Person(string name);
    // 自定义拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p);

    /// MARK: 成员函数 成员函数 后加const,修饰的是 this指针，让指针指向的值也不可以修改
    void showPersonInfo() const;

    int m_age;      // 年龄
    int *m_height;  // 身高
    string name;
};
// 全局测试函数
void personTestHandle1 ();
void personTestHandle2 ();
void personTestHandle3 ();


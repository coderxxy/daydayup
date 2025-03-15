#pragma once
#include <iostream>
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
    // 自定义拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p);

    int m_age;      // 年龄
    int *m_height;  // 身高
};
// 全局测试函数
void personTestHandle1 ();
void personTestHandle2 ();
void personTestHandle3 ();


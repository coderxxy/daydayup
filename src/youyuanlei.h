#pragma once
#include <iostream>
#include <string>

using namespace std;

class youyuanleiB;
class youyuanleiA
{
private:
    /* data */
    youyuanleiB *yyuanB;
public:
    youyuanleiA(/* args */);
    ~youyuanleiA();

    void visit();
};


class youyuanleiB
{
    // 声明youyuanleiA为友元类
    friend class youyuanleiA;

private:
    /* data */
    string m_bedRoom;
public:
    string m_sittingRoom;
    youyuanleiB(/* args */);
    ~youyuanleiB();
};

void youyuanTest ();
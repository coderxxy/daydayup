#include "youyuanlei.h"

youyuanleiA::youyuanleiA(/* args */)
{
    yyuanB = new youyuanleiB;
}

youyuanleiA::~youyuanleiA()
{
}

void youyuanleiA::visit()
{
    cout << "正在访问" << yyuanB->m_sittingRoom <<endl;
    cout << "正在访问" << yyuanB->m_bedRoom <<endl;
}


youyuanleiB::youyuanleiB(/* args */)
{
    this->m_sittingRoom = "客厅";
    this->m_bedRoom = "卧室";
}

youyuanleiB::~youyuanleiB()
{
}

void youyuanTest ()
{
    youyuanleiA *yyuanA = new youyuanleiA;
    yyuanA->visit();
}

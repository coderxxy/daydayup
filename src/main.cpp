#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "functions.h"
#include "structs.h"
#include "contactsSystemManager.h"

#include "rectangledemo.h"
#include "Person.h"

#include "youyuanlei.h"

#include "AbstractCalculator.cpp"

void calculatorTest();

int main(int argc, char const *argv[])
{
    // cout <<"hello world!\n"<<endl;
    // int a = 10;
    // unsigned long length = sizeof(a);
    // cout <<"数据类型所占内存大小：\n"<<length<<endl;

    // playGameAction();
    // daffodilHandle();
    // clickDeskGame();
    // multiplicationTable();
    // reverseHandle();
    // sortHandle();
//    swapHandle(10, 20);

//    structArrayHandle();
//structPointHandle();
// structWithStructHandle();

// teacherInfoAction();
// sortGameHeroAction();

// contactsSystemManagerAction();
// rectangleTest();
// initHandle();
// personTestHandle1();
// personTestHandle2();

// youyuanTest();
calculatorTest();
    // system("pause");
    return 0;
}


// 测试
void calculatorTest()
{
    AddCalculator *addCal = new AddCalculator;
    addCal->num1 = 100;
    addCal->num2 = 200;
    cout << "加法结果：" << addCal->getResult() <<endl;
}



// 获取个位     n%10
// 获取十位     n/10
// 获取百位     n/100
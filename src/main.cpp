#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "functions.h"
#include "structs.h"
#include "contactsSystemManager.h"

#include "rectangledemo.cpp"

void rectangleTest();

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
rectangleTest();
    // system("pause");
    

    return 0;
}

// 利用全局函数判断 是否相等
bool isSameRectangle(rectangledemo &r1, rectangledemo &r2)
{
    bool isequal = false;
    if (r1.getL() == r2.getL() && r1.getW() == r2.getW() && r1.getH()== r2.getH())
    {
        isequal = true;
    }
    return isequal;
}

/// @brief 立方体测试
void rectangleTest()
{
    rectangledemo rectangle;
    rectangle.setL(10);
    rectangle.setW(10);
    rectangle.setH(10);

    cout <<"面积："<<rectangle.calculateS()<<endl;
    cout <<"体积："<<rectangle.calculateV()<<endl;
    //

    rectangledemo rectangle1;
    rectangle1.setL(11);
    rectangle1.setW(10);
    rectangle1.setH(10);

    cout <<"面积："<<rectangle1.calculateS()<<endl;
    cout <<"体积："<<rectangle1.calculateV()<<endl;

    bool ret1 = isSameRectangle(rectangle, rectangle1);
    bool ret2 = rectangle.isSameByClass(rectangle1);

    cout <<"是否相等:"<<ret1<<endl;
    cout <<"是否相等:"<<ret2<<endl;
}

// 获取个位     n%10
// 获取十位     n/10
// 获取百位     n/100
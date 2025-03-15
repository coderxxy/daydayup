#include <iostream>
#include <string>
using namespace std;

/***
 * 立方体设计
 * 1、设计立方体类
 * 2、设计属性
 * 3、求面积和体积
 * 4、分别用全局、成员函数判断两个立方体相等
*/
class rectangledemo
{
private:
    int m_l;
    int m_w;
    int m_h;
    
public:
    void setL(int l);
    int getL();

    void setW(int w);
    int getW();

    void setH(int h);
    int getH();
    // 求s
    int calculateS();
    // 求v
    int calculateV();

    bool isSameByClass (rectangledemo &r);
};
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
    void setL(int l)
    {
        m_l = l;
    }
    int getL()
    {
        return m_l;
    }

    void setW(int w)
    {
        m_w = w;
    }
    int getW()
    {
        return m_w;
    }

    void setH(int h)
    {
        m_h = h;
    }
    int getH()
    {
        return m_h;
    }
    // 求s
    int calculateS()
    {
        return 2*m_l*m_w + 2*m_w*m_h + 2*m_l*m_h;
    }
    // 求v
    int calculateV()
    {
        return m_l*m_w*m_h;
    }

    bool isSameByClass (rectangledemo &r)
    {
        bool isequal = false;
        if (m_l == r.getL() && m_w == r.getW() && m_h == r.getH())
        {
            isequal = true;
        }
            return isequal;
    }
};





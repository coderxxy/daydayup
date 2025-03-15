#include "rectangledemo.h"

// 构造函数
rectangledemo::rectangledemo()
{
    cout << "构造函数\n" <<endl;
}
// 析构函数
rectangledemo::~rectangledemo()
{
    cout << "析构函数" << endl;
}
// 有参构造函数
rectangledemo::rectangledemo(int length, int width, int height)
{
    this->setL(length);
    this->setW(width);
    this->setH(height);

    int s = this->calculateS();
    int v = this->calculateV();

    cout <<"s:"<<s<<endl;
    cout<<"v:"<<v<<endl;
}
// 拷贝构造函数
rectangledemo::rectangledemo(const rectangledemo &rt)
{
    cout <<"拷贝构造函数\n"<<endl;
}

void rectangledemo::setL(int l)
{
    m_l = l;
}
int rectangledemo::getL()
{
    return m_l;
}

void rectangledemo::setW(int w)
{
    m_w = w;
}
int rectangledemo::getW()
{
    return m_w;
}

void rectangledemo::setH(int h)
{
    m_h = h;
}
int rectangledemo::getH()
{
    return m_h;
}
// 求s
int rectangledemo::calculateS()
{
    return 2*m_l*m_w + 2*m_w*m_h + 2*m_l*m_h;
}
// 求v
int rectangledemo::calculateV()
{
    return m_l*m_w*m_h;
}

bool rectangledemo::isSameByClass (rectangledemo &r)
{
    bool isequal = false;
    if (m_l == r.getL() && m_w == r.getW() && m_h == r.getH())
    {
        isequal = true;
    }
        return isequal;
}


// public method

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

void initHandle()
{
    // 匿名构造函数 
    // 特点：当前行执行结束后，会被系统立即回收, 个人理解：未创建接收对象，开辟内存空间
    rectangledemo rtl = rectangledemo(10, 20, 30);
    // 不要利用拷贝构造函数 初始化匿名对象
}



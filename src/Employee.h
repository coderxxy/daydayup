#pragma once                // 防止头文件包含
#include <iostream>         // 包含输入输出流头文件
using namespace std;        // 使用标准命名空间
#include <string.h>

// 职工抽象类
class Employee
{
private:
    /* data */
public:
    // properties
    int m_id;       // 职工编号
    string m_name;  // 职工姓名
    int m_deptId;   // 职工部门编号

    // method
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

    virtual ~Employee();
};

// 问题
// EmployeeManager.cpp:320:13: warning: delete called on 'Employee' that is abstract but has non-virtual destructor [-Wdelete-abstract-non-virtual-dtor]
//   320 |             delete this->m_empArray[index];
//       |             ^
// 1 warning generated.
// class Employee {
//     public:
//         // 虚析构函数
//         virtual ~Employee() {
//             // 这里可以添加清理资源的代码
//         }
    
//         // 其他成员函数和属性
//         virtual void work() = 0; // 纯虚函数，表示这是一个抽象类
//     };
    
//     class Manager : public Employee {
//     public:
//         ~Manager() {
//             // 这里可以添加Manager特有的清理资源的代码
//         }
    
//         void work() override {
//             // 实现Manager的工作方式
//         }
//     };
    
//     int main() {
//         Employee* emp = new Manager();
//         // ... 使用emp做一些工作
//         delete emp; // 这里会先调用Manager的析构函数，然后调用Employee的析构函数
//         return 0;
//     }
    
#pragma once                // 防止头文件包含
#include <iostream>         // 包含输入输出流头文件
using namespace std;        // 使用标准命名空间
#include <string.h>
/// 经理
#include "Employee.h"

class EmployeeWorkerManager : public Employee
{
private:
    /* data */
public:
    EmployeeWorkerManager(int id, string name, int dId);
    ~EmployeeWorkerManager();
        // method
    void showInfo();
    string getDeptName();
};



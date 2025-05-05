#pragma once                // 防止头文件包含
#include <iostream>         // 包含输入输出流头文件
using namespace std;        // 使用标准命名空间
#include <string.h>

#include "Employee.h"

class EmployeeWorker : public Employee
{
private:
    /* data */
public:
    EmployeeWorker (int id, string name, int dId);
    ~EmployeeWorker ();

    // method
    void showInfo();
    string getDeptName();
};






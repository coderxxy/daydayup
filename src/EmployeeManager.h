#pragma once                // 防止头文件包含
#include <iostream>         // 包含输入输出流头文件
using namespace std;        // 使用标准命名空间

#include <fstream>
#define FILENAME "empFile.txt"

#include "Employee.h"

class EmployeeManager
{
private:

    int m_empNum;           // 人数
    Employee **m_empArray;  // 员工数组指针 
    bool m_fileIsEmpty;     // 文件是否为空标识
    /** 初始化数据 */ 
    void initData(string tipMsg);
    /** 初始化职工数据 */
    void initEmp();
    // 获取人数
    int getEmpNum();
    /** 判断是否存在该员工 */
    int isExist(int id);
    /** 判断输入的编号是否已存在 */
    bool isIdExist(int id);
    /* 保存数据 */
    void save();
public:
    EmployeeManager();      // 构造函数
    ~EmployeeManager();     // 析构函数

    void employeeManagerAction();
    //
    void showMenuAction();    // 展示功能菜单
    /* 退出 */ 
    void exitAction();  
    /* 显示 */     
    void showEmployeerInfo();
    /* 增加 */    
    void addEmployeerInfo();    
    /* 删除 */ 
    void deleteEmployeerInfo();  
    /* edit */
    void editEmployeerInfo();
    /* search */
    void searchEmployeer();
    /* sort */
    void sortAction();
    /* clean */
    void cleanAction();
};

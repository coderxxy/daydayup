#include "EmployeeWorker.h"

EmployeeWorker ::EmployeeWorker (int id, string name, int dId)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = dId;
}

EmployeeWorker ::~EmployeeWorker ()
{
}

void EmployeeWorker :: showInfo ()
{
    cout<< "工号：" << this->m_id
    << "\t姓名：" << this->m_name
    << "\t职位：" << this->getDeptName() 
    << "\t岗位职责：完成经理分配的工作内容。" << endl;
}

string EmployeeWorker :: getDeptName ()
{
    return string("员工");
}
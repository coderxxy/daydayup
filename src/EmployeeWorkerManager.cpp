#include "EmployeeWorkerManager.h"

EmployeeWorkerManager::EmployeeWorkerManager(int id, string name, int dId)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptId = dId;
}
// 析构函数
EmployeeWorkerManager::~EmployeeWorkerManager()
{

}
// TODO: 显示个人信息
void EmployeeWorkerManager::showInfo()
{
    cout<< "工号：" << this->m_id
    << "\t姓名：" << this->m_name
    << "\t职位：" << this->getDeptName() 
    << "\t岗位职责：完成老板分配的工作内容。" << endl;
}
// TODO: 获取职位名称
string EmployeeWorkerManager::getDeptName()
{
    return string("经理");
}
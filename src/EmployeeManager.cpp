#include "EmployeeManager.h"

#include "EmployeeWorker.h"

#include "EmployeeWorkerManager.h"

EmployeeManager::EmployeeManager()
{
    // 初始化参数
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 用输入方式打开文件 -- 读文件
    // 1、文件不存在
    if (!ifs.is_open())
    {
        this->initData("文件不存在");
        ifs.close();
        return;
    }
    // 2、文件存在 但文件为空 ifs.eof()
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->initData("文件为空");
        ifs.close();
        return;
    }
    // 3、有数据
    int num = this->getEmpNum();
    cout << "当前职工人数：" << num << endl;
    this->m_empNum = num;
    // 开辟空间
    this->m_empArray = new Employee *[this->m_empNum];
    // 将文件中的数据 存到数组中
    this->initEmp();
}
EmployeeManager::~EmployeeManager()
{
    if (this->m_empArray != NULL)
    {
        for (int i = 0; i < this->m_empNum; i++)
        {
            delete this->m_empArray[i];
            this->m_empArray[i] = NULL;
        }
        delete[] this->m_empArray;
        this->m_empArray = NULL;
    }
}
// 初始化基本数据
void EmployeeManager::initData(string tipMsg)
{
    cout << tipMsg << endl;
    this->m_empNum = 0;
    this->m_fileIsEmpty = true;
    this->m_empArray = NULL;
}
// TODO: 初始化职工
void EmployeeManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int idx = 0;
    // 遍历文件
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Employee *worker = NULL;
        if (1 == dId)
        {
            worker = new EmployeeWorkerManager(id, name, dId);
        }
        else if (2 == dId)
        {
            worker = new EmployeeWorker(id, name, dId);
        }
        // 存放在数组中
        this->m_empArray[idx] = worker;
        idx++;
    }
    ifs.close();
}
void EmployeeManager::employeeManagerAction()
{
    // Employee *manager = NULL;
    // manager = new EmployeeWorkerManager(2, "张三", 2);
    // manager->showInfo();
    // delete manager;

    // Employee *worker = NULL;
    // worker = new EmployeeWorker(3, "李四", 3);
    // worker->showInfo();
    // delete worker;

    int actionIdx = -1;
    while (true)
    {
        showMenuAction();
        //
        cout << "请输入您的操作编号：" << endl;
        cin >> actionIdx;

        switch (actionIdx)
        {
        case 0: // 退出
            this->exitAction();
            // exitAction();
            break;
        case 1: // 添加
            addEmployeerInfo();
            break;
        case 2: // 显示信息
            showEmployeerInfo();
            break;
        case 3: // 删除
            deleteEmployeerInfo();
            break;
        case 4: // 修改
            editEmployeerInfo();
            break;
        case 5: // 查找
            searchEmployeer();
            break;
        case 6: // 排序
            sortAction();
            break;
        case 7: // 清空
            cleanAction();
            break;
        default:
            system("cls"); // 清屏
            break;
        }
    }
}
// TODO: 显示功能菜单
void EmployeeManager::showMenuAction()
{
    cout << "**********************************************" << endl;
    string menus[] = {"欢迎使用职工管理系统!", "0.退出管理系统", "1.增加职工信息", "2.显示职工信息", "3.删除离职职工", "4.修改职工信息", "5.查找职工信息", "6.按照编号排序", "7.清空所有文档"};
    int menuLength = sizeof(menus) / sizeof(menus[0]);
    for (int i = 0; i < menuLength; i++)
    {
        string menu = menus[i];
        cout << "*********** " << menu << " ***********" << endl;
    }
    cout << "**********************************************" << endl;
}
/* 退出 */
void EmployeeManager::exitAction()
{
    cout << "欢迎下次使用!" << endl;
    system("pause");
    exit(0);
}
/* 增加 */
void EmployeeManager::addEmployeerInfo()
{
    cout << "请输入添加员工数量：" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum <= 0)
    {
        cout << "输入有误!" << endl;
    }
    else
    {
        // 计算添加新空间大小
        int newSize = this->m_empNum + addNum; // 新空间大小=原人数+新增人数
        // 开辟新空间
        Employee **newSpase = new Employee *[newSize];
        // 原空间数据，拷贝到新空间
        if (this->m_empArray != NULL)
        {
            for (int i = 0; i < this->m_empNum; i++)
            {
                newSpase[i] = this->m_empArray[i];
            }
        }
        // 添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dIdx; // 部门编号

            cout << "请输入" << i + 1 << " 个新职工编号" << endl;
            cin >> id;
            // 判断该编号是否已存在
            bool isExist = this->isIdExist(id);
            if (isExist == false)
            {
                cout << "请输入第" << i + 1 << " 个新职工姓名" << endl;
                cin >> name;

                cout << "请选择该职工岗位" << endl;
                cout << "1、普通员工" << endl;
                cout << "2、经理" << endl;
                cin >> dIdx;

                Employee *worker = NULL;

                switch (dIdx)
                {
                case 1:
                    worker = new EmployeeWorkerManager(id, name, 1);
                    break;
                case 2:
                    worker = new EmployeeWorker(id, name, 2);
                    break;
                default:
                    break;
                }
                // 将创建职工职责，保存到数组中
                newSpase[this->m_empNum + i] = worker;
            }
            else{
                
                if (addNum == 1)
                {
                    cout<<"该编号已存在！添加失败！"<<endl;
                    return;
                }
                else{
                    addNum --;
                    cout<<"该编号已存在！"<<endl;
                    continue;
                }
            }
        }
        // 释放原有空间
        delete[] this->m_empArray;
        // 更改新空间的指向
        this->m_empArray = newSpase;
        // 更新新职工人数
        this->m_empNum = newSize;
        // 提示添加成功
        cout << "成功添加" << addNum << "名新职工" << endl;
        // 更新文件是否为空标识
        this->m_fileIsEmpty = false;
        // 保存
        this->save();
    }
    // 按任意键清屏 回到上级目录
    system("pause");
    system("cls");
}
// TODO: 显示职工信息
void EmployeeManager::showEmployeerInfo()
{
    if (this->m_fileIsEmpty)
    {
        cout << "文件不存在或为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_empNum; i++)
        {
            // 利用多态调用显示接口
            this->m_empArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}
// TODO: 删除
void EmployeeManager::deleteEmployeerInfo()
{
    if (this->m_fileIsEmpty)
    {
        cout << "文件不存在或数据为空!" << endl;
    }
    else
    {
        cout << "输入要删除的职工ID" << endl;
        int cinId = -1;
        cin >> cinId;
        int idx = this->isExist(cinId);
        if (-1 == idx)
        {
            cout << "您要删除的职工不存在！" << endl;
        }
        else
        {
            for (int i = idx; i < this->m_empNum - 1; i++)
            {
                // 数据前移
                this->m_empArray[i] = this->m_empArray[i + 1];
            }
            // 更新数组中记录个数
            this->m_empNum--;
            // 数据同步更新到文件中
            this->save();
            cout << "删除成功！" << endl;
        }
    }
    system("pause");
    system("cls");
}
// TODO: edit
void EmployeeManager::editEmployeerInfo()
{
    if (this->m_fileIsEmpty)
    {
        cout << "文件不存在或数据为空！" << endl;
    }
    else
    {
        cout << "请输入修改的职工编号:" << endl;
        int id;
        cin >> id;

        int index = this->isExist(id);
        if (index == -1)
        {
            cout << "输入错误或不存在!" << endl;
        }
        else
        {
            delete this->m_empArray[index];

            int newId = 0;
            string name = "";
            int dId = 0;

            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;

            cout << "请输入新姓名：" << endl;
            cin >> name;

            cout << "请输入岗位：" << endl;
            cout << "1、经理" << endl;
            cout << "2、普工" << endl;
            cin >> dId;

            Employee *worker = NULL;
            switch (dId)
            {
            case 1:
                worker = new EmployeeWorkerManager(newId, name, dId);
                break;
            case 2:
                worker = new EmployeeWorker(newId, name, dId);
                break;
            default:
                break;
            }
            this->m_empArray[index] = worker;
            cout << "修改成功！" << this->m_empArray[index]->m_deptId << endl;
            // 保存到文件中
            this->save();
        }
    }
    // 按任意键 清屏
    system("pause");
    system("cls");
}
// TODO: search
void EmployeeManager::searchEmployeer()
{
    if (this->m_fileIsEmpty)
    {
        cout << "文件不存在或数据为空！" << endl;
    }
    else
    {
        cout << "请输入查找方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (1 == select)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int index = this->isExist(id);
            if (-1 == index)
            {
                cout << "该编号职工不存在！" << endl;
            }
            else
            {
                cout << "查找成功，该职工信息如下：" << endl;
                this->m_empArray[index]->showInfo();
            }
        }
        else if (2 == select)
        {
            cout << "请输入职工姓名：" << endl;
            string name;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < this->m_empNum; i++)
            {
                if (this->m_empArray[i]->m_name == name)
                {
                    flag = true;
                    cout << "查找成功，职工编号为：" << this->m_empArray[i]->m_id << "号的信息如下：" << endl;
                    this->m_empArray[i]->showInfo();
                    break;
                }
            }
            if (flag == false)
            {
                cout << "查找失败，未查询到该职工信息!" << endl;
            }
        }
        else
        {
            cout << "请按提示输入合法的查找方式!" << endl;
            this->searchEmployeer();
        }
    }
    // 按任意键 清屏
    system("pause");
    system("cls");
}
// TODO: sort
void EmployeeManager::sortAction()
{
    cout<<"暂未实现!"<<endl;
}
// TODO: clean
void EmployeeManager::cleanAction()
{
    if (this->m_fileIsEmpty)
    {
        cout << "文件不存在或数据为空！" << endl;
    }
    else{
        cout<<"确认清空？"<<endl;
        cout<<"1、确认"<<endl;
        cout<<"2、取消"<<endl;

        int selIdx = 0;
        cin>>selIdx;

        if (1 == selIdx)
        {
            // 打开模式 ios::trunc 如果存在删除文件并重新创建
            ofstream ofs(FILENAME, ios::trunc);
            ofs.close();

            if (this->m_empArray != NULL)
            {
                for (int i = 0; i < this->m_empNum; i++)
                {
                    if (this->m_empArray[i] != NULL)
                    {
                        delete this->m_empArray[i];
                        this->m_empArray[i] = NULL;
                    }
                }
                this->m_empNum = 0;
                delete[] this->m_empArray;
                this->m_empArray = NULL;
                this->m_fileIsEmpty = true;
            }
            cout<<"清空成功！"<<endl;
        }
        else if (2 == selIdx)
        {
            // TODO:  NO ACTION
        }
        else{
            cout<<"输入的操作指令错误!"<<endl;
        }
    }

    system("pause");
    system("cls");
}
// TODO: 保存数据
void EmployeeManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 用输出方式打开文件 -- 写文件
    // 将每个人的数据写入到文件中
    for (int i = 0; i < this->m_empNum; i++)
    {
        ofs << this->m_empArray[i]->m_id << " "
            << this->m_empArray[i]->m_name << " "
            << this->m_empArray[i]->m_deptId << endl;
    }
    // 关闭文件
    ofs.close();
}
// TODO: 统计人数
int EmployeeManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++; // 记录人数
    }
    ifs.close();
    return num;
}
// TODO: 判断是否存在该员工
int EmployeeManager::isExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_empNum; i++)
    {
        if (this->m_empArray[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
// TODO: 新增员工时判断输入的职工编号是否已被占用
bool EmployeeManager::isIdExist(int id)
{
    bool isExist = false;
    for (int i = 0; i < this->m_empNum; i++)
    {
        if (this->m_empArray[i]->m_id == id)
        {
            isExist = true;
            break;
        }
    }
    return isExist;
}
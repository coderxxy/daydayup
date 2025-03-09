//
// Created by coderxxy on 2025/3/9.
//

#include "contactsSystemManager.h"

/// 通讯录管理系统功能【最大上限1000，包含（姓名、性别、年龄、联系电话、家庭地址）】
/// 最大上限
#define MAX_SIZE_LIMIT  1000

/// @brief 通讯录联系人信息model
struct ContactPersonModel
{
    string name;    // 姓名
    int gender;     // 性别 1:男 2:女
    int age;        // 年龄
    string mobile;     // 联系电话
    string address; // 地址
};
/// @brief 通讯录
struct ContactsModel
{
    ContactPersonModel contacts [MAX_SIZE_LIMIT];         // 联系人数组
    int m_size;                                           // 当前数量
};

void existAction ()
{
    std::cout<<"程序结束，按任意键退出..."<<endl;
    // cout << "Press Enter to continue...";
    // getchar(); // 等待用户输入
    std::cin.get();
}

// todo: 显示功能菜单；
void showMenuAction ()
{
    string actions[] = {
        "1、添加联系人；", "2、显示联系人；", "3、删除联系人；",
        "4、查找联系人；", "5、修改联系人；", "6、清空联系人；",
        "0、退出通讯录。"
    };
    string starStr = "*****   ";
    string endStr = "   *****";
    string longStartStr = "*****************************";
    cout << longStartStr << endl;
    int len = sizeof(actions)/sizeof(actions[0]);
    for (int i = 0; i < len; i++)
    {
        string str = actions[i];
        str = starStr + str;
        str += endStr;
        cout << str << endl;
    }
    cout << longStartStr << endl;
}

// todo: 查找是否存在要添加的成员
int isExist (ContactsModel *contacts, string name)
{
    int idx = -1;
    for (int i = 0; i < contacts->m_size; i++)
    {
        ContactPersonModel tempPerson = contacts->contacts[i];
        if (name == tempPerson.name)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

// todo: 添加联系人
void addPersonHandle(ContactsModel *contacts)
{
    if (contacts->m_size>=MAX_SIZE_LIMIT)
    {
        cout<<"已达到最大存储值，无法添加！\n"<<endl;
        return;
    }
    
    cout << "请输入姓名:\n" << endl;
    string name;
    cin >> name;
    contacts->contacts[contacts->m_size].name = name;
    
    cout << "请输入性别(1:男， 2:女):\n" << endl;
    int sex = 0;
    while (true)
    {
        cin>>sex;
        if (sex !=1 && sex != 2){
            cout<<"输入格式不对，请规范格式!【1:男， 2:女】\n";
        }
        else{
            contacts->contacts[contacts->m_size].gender = sex;
            break;
        }
    }

    cout << "请输入年龄:\n" << endl;
    int age = 0;
    while (true)
    {
        cin>>age;
        if (age <=0 || age>120)
        {
            cout<<"请输入合适的年龄1~120!\n"<<endl;
        }
        else{
            contacts->contacts[contacts->m_size].age = age;
            break;
        }
    }
    
    cout << "请输入联系电话:\n" << endl;
    string mobile;
    cin>>mobile;
    contacts->contacts[contacts->m_size].mobile = mobile;

    cout << "请输入家庭住址:\n" << endl;
    string address;
    cin >> address;
    contacts->contacts[contacts->m_size].address = address;
    // 更新人数
    contacts->m_size++;
    cout<<"\n"<<"录入成功!\n"<<endl;
    // 清屏
    // system("pause");
    // system("cls");
    existAction();
}
// todo: 显示联系人
void showPersonInfoHandle (ContactsModel *contacts)
{
    if (contacts->m_size <= 0)
    {
        std::cout<<"暂未录入,通讯录空空如也！\n"<<endl;
        return;
    }

    cout<<"请输入姓名:\n"<<endl;
    string name;
    cin>>name;
    bool successed = false;
    //
    for (int i = 0; i < contacts->m_size; i++)
    {
        ContactPersonModel person = contacts->contacts[i];
        if (person.name == name)
        {
            successed = true;
            cout <<"姓名：" << person.name << "\t";
            cout <<"年龄：" << person.age << "\t";
            cout <<"性别：" << (person.gender == 1 ?"男":"女") << "\t";
            cout <<"联系电话：" << person.mobile << "\t";
            cout <<"家庭住址：" << person.address << endl;
            break;
        }
    }
    //
    if (!successed)
    {
        existAction();
    }
}

// todo: 删除联系人
void deletePersonHandle(ContactsModel *contacts)
{
    std::cout<<"请输入要删除的人员：\n"<<endl;
    string name;
    cin >> name;
    int idx = isExist(contacts, name);
    if (idx == -1)
    {
        std::cout<<"不存在！\n"<<endl;
        return;
    }
    
    for (int i = 0; i < contacts->m_size; i++)
    {
        contacts->contacts[idx] = contacts->contacts[idx+1];
    }
    contacts->m_size --;
    std::cout<<"delete successed!\n"<<endl;
}

// todo: 查找联系人
void searchPersonHandle (ContactsModel *contacts)
{
    cout << "请输入查找人的姓名:\n" << endl;
    string name;
    cin >> name;
    int idx = isExist(contacts, name);

    if (idx == -1)
    {
        cout << "查无此人!\n" << endl;
        //
        existAction();
        return;
    }
    
    for (int i = 0; i < contacts->m_size; i++)
    {
        ContactPersonModel person = contacts->contacts[i];
        if (person.name == name)
        {
            std::cout<<"在列表中第: "<<i<<"  个\n"<<endl;
            cout <<"姓名：" << person.name << "\t";
            cout <<"年龄：" << person.age << "\t";
            cout <<"性别：" << (person.gender==1?"男":"女") << "\t";
            cout <<"联系电话：" << person.mobile << "\t";
            cout <<"家庭住址：" << person.address << endl;
            break;
        }
    }
    existAction();
}

// todo: 修改联系人
void modifyAction(ContactsModel *contacts)
{
    std::cout<<"请输入要修改的人员姓名：\n"<<endl;
    string name;
    cin>>name;
    int idx = isExist(contacts, name);
    if (idx == -1)
    {
        cout<<"未找到该人员信息\n"<<endl;
    }
    else{
        cout << "请输入姓名:\n" << endl;
        string name;
        cin >> name;
        contacts->contacts[idx].name = name;
        
        cout << "请输入性别(1:男， 2:女):\n" << endl;
        int sex = 0;
        while (true)
        {
            cin>>sex;
            if (sex !=1 && sex != 2){
                cout<<"输入格式不对，请规范格式!【1:男， 2:女】\n";
            }
            else{
                contacts->contacts[idx].gender = sex;
                break;
            }
        }
    
        cout << "请输入年龄:\n" << endl;
        int age = 0;
        while (true)
        {
            cin>>age;
            if (age <=0 || age>120)
            {
                cout<<"请输入合适的年龄1~120!\n"<<endl;
            }
            else{
                contacts->contacts[idx].age = age;
                break;
            }
        }
        
        cout << "请输入联系电话:\n" << endl;
        string mobile;
        cin>>mobile;
        contacts->contacts[idx].mobile = mobile;
    
        cout << "请输入家庭住址:\n" << endl;
        string address;
        cin >> address;
        contacts->contacts[idx].address = address;
        //
        std::cout<<"modify successed!\n"<<endl;
        //
        existAction();
    }
}

// todo: 清空联系人
void clearAction (ContactsModel *contacts)
{
    contacts->m_size = 0;
    std::cout<<"数据已清空,通讯录中人员个数为："<<contacts->m_size<<endl; 
    existAction();
}

// todo: 对外接口
void contactsSystemManagerAction ()
{
    //
    ContactsModel contactsModel;    // 通讯录厨师话
    contactsModel.m_size = 0;       // 厨师话当前人员个数
    //
    int selectIdx = 0;  //操作编号
    while (true)
    {
        // 显示操作菜单
        showMenuAction();
        //
        cin >> selectIdx;
        switch (selectIdx)
        {
            case 0:
            {
                cout<<"欢迎下次使用通讯录管理系统!\n"<<endl;
                system("pause");
                return;
            }
            break;
            case 1:
            {
                addPersonHandle(&contactsModel);
            }
            break;
            case 2:
            {
                showPersonInfoHandle(&contactsModel);
            }
            break;
            case 3:
            {
                deletePersonHandle(&contactsModel);
            }
            break;
            case 4:
            {
                searchPersonHandle(&contactsModel);
            }
            break;
            case 5:
            {
                modifyAction(&contactsModel);
            }
            break;
            case 6:
            {
                clearAction(&contactsModel);
            }
            break;
    
            default:
            break;
        }
    }
}
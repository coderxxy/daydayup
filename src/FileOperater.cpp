#include "FileOperater.h"
#include "Person.h"

FileOperater::FileOperater(/* args */)
{
}

FileOperater::~FileOperater()
{
   cout<<"析构函数"<<endl;
}

void FileOperater::fileRWHandle(){
    /***
     * 1、导入头文件
     * 2、创建文件流对象
    */
   // TODO: 写内容
   ofstream ofs;
   // 指定打开方式
   ofs.open("test.txt", ios::out);
   if (!ofs.is_open())
   {
      cout << "文件打开时失败!" << endl;
      return;
   }
   
   // 写内容
   ofs<<"name:zhangsan"<<endl;
   ofs<<"gender:男"<<endl;
   ofs<<"age:18"<<endl;
   cout<<"文件写入成功!"<<endl;
   ofs.close();
   // TODO: 读文件
   ifstream ifs;
   ifs.open("test.txt", ios::in);
   if (!ifs.is_open())
   {
        cout<<"open state, failure!"<<endl;
        return;
   }
   cout<<"读取文件"<<endl;
   // 以下四种读文件方式
   // 1
   char buf[1024] = {0};
   while (ifs>>buf)
   {
    cout<<buf<<endl;
   }
   // 2
//    char buf[1024] = {0};
   // while (ifs.getline(buf, sizeof(buf)))
   // {
   //  cout<<buf<<endl;
   // }
   //3、
   // string buf_str;
   // while (getline(ifs, buf_str))
   // {
   //  cout<<buf_str<<endl;
   // }
   // 4、不推荐，一个个字符读取
//    char c;
//    while ((c=ifs.get()) != EOF)
//    {
//     cout << c;
//    }
   
   //
   ifs.close();
}
// TODO: 二进制方式操作文件
void FileOperater::fileRWBinary(){
   ofstream ofs;
   ofs.open("person.txt", ios::out | ios::binary); // 二进制方式写文件
   Person p = Person("张三", 18);
   // 写入
   ofs.write((const char*)&p, sizeof(Person));
   ofs.close();
   // 读取
   ifstream ifs;
   ifs.open("person.txt", ios::in | ios::binary); // 二进制方式读文件
   if (!ifs.is_open())
   {
      cout<<"read failed!"<<endl;
      return;
   }
   Person p1;
   ifs.read((char *)&p1, sizeof(Person));
   cout<<"姓名："<<p1.name<<" 年龄："<<p1.m_age<<endl;
}

void fileOperationHandle()
{
     FileOperater *file = new FileOperater();
   //   file->fileRWHandle();
   file->fileRWBinary();
}

/*** 
 * 文件操作流程
 * 1、包含头文件
 * 2、创建流对象
 * 3、打开文件
 * 4、写文件
 * 5、关闭
*/
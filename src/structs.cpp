//
// Created by coderxxy on 2025/3/5.
//
#include "structs.h"
#include <string.h>
/// 学生结构体
struct Student{
    /// 姓名
    string name;
    /// 年龄
    int age;
    /// 分数
    int score;
    /// 身高
    double height;
};
/// teacher
struct Teacher{
    // 编号
    int id;
    // 姓名
    string name;
    // 课程
    string project;
    // 辅导的学生
    Student stu;
};
// todo: 结构体数组
void structArrayHandle()
{
    struct Student stuArr[3] = {
            {"张三", 18, 80},
            {"李四", 20, 88},
            {"王五", 22, 90}
    };

    for (int i = 0; i < sizeof(stuArr)/ sizeof(stuArr[0]); ++i) {
        struct Student stu = stuArr[i];
        cout<<"姓名："<<stu.name<<" 年龄："<<stu.age<<" 分数："<<stu.score<<endl;
    }
}
// TODO: 结构体指针
void structPointHandle()
{
    Student stu;
//    stu.name = "Frank";
//    stu.age = 35;
//    stu.height = 164;
    Student *s = &stu;
    s->name = "Jerry";
    s->age = 35;
    s->height = 163;
    cout<<stu.name<<endl;
}
// todo: 结构体嵌套结构体
void structWithStructHandle()
{
    Teacher teacher;
//    Student student;

    teacher.name = "Doctor Frank";
    teacher.id = 10000;
    teacher.project = "c++";
    teacher.stu.name = "Cat";
    teacher.stu.score = 90;

    cout<<teacher.name<<"老师辅导的学生"<<teacher.stu.name<<"考试得了"<<teacher.stu.score<<endl;
}
// todo: 结构体做函数参数
// 值传递 内部形参值改变不会影响原数据
void structParamHandle(Student stu)
{
    stu.age = 100;
    cout<<"姓名："<<stu.name<<" 年龄："<<stu.age<<" 分数："<<stu.score<<endl;
}
// 地址传递 内部形参改变会影响原数据
void structParamStu(Student *stu)
{
    stu->age = 100;
    cout<<"姓名："<<stu->name<<" 年龄："<<stu->age<<" 分数："<<stu->score<<endl;
}
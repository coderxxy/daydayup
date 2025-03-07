//
// Created by coderxxy on 2025/3/5.
//
#include "structs.h"
#include <string.h>
#include <ctime>

#include "publicStructs.h"
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

/***
 * 1、创建3名老师的数组
 * 2、通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
 * 3、打印所有老师及所带的学生信息
*/
// todo: 随机分数
 int stuScore ()
 {
    // // 添加随机数种子，利用当前系统时间生成随机数，防止随机数重复
    // unsigned int second = time(NULL);
    // srand(second);
    // 1到100随机数
    // int randomNum = rand()%100+1;
    int randomNum = rand()%61+40;
    return randomNum;
 }

// todo: 打印所有信息
void printInfoHandle(Teacher teacher)
{
    cout << "老师：" <<teacher.name << endl;
    for (int i = 0; i < sizeof(teacher.sArray)/sizeof(teacher.sArray[0]); i++)
    {
        Student stu = teacher.sArray[i];
        cout << "\t学生：" <<stu.name << "\t分数:" << stu.score << endl;
    }
}

// todo:给老师学生赋值
void teacherAndStuInfoHandle (Teacher tArray[], int length)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < length; i++)
    {
        tArray[i].name = "Teacher_";
        tArray[i].name += nameSeed[i];
        // 计算学生个数
        int stuLen = sizeof(tArray[i].sArray)/sizeof(tArray[i].sArray[0]);
        for (int j = 0; j < stuLen; j++)
        {
            tArray[i].sArray[j].name = "Student";
            tArray[i].sArray[j].name += nameSeed[j];
            tArray[i].sArray[j].score = stuScore();
        }
        // 打印所有信息
        printInfoHandle(tArray[i]);
    }
}

// todo: 
void teacherInfoAction()
{
    // 添加随机数种子，利用当前系统时间生成随机数，防止随机数重复
    unsigned int second = time(NULL);
    srand(second);
    Teacher teacher[3]; // 创建3名老师数组
    teacherAndStuInfoHandle(teacher, sizeof(teacher)/sizeof(teacher[0])); // 给老师学生赋值
}


// todo: 冒泡排序【年龄】 输出英雄信息

void sortHeroHandle(GameHero heros[], int count)
{
    GameHero tempHero;
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            GameHero hero = heros[j];
            GameHero heroInside = heros[j+1];
            if (hero.age > heroInside.age)
            {
                tempHero = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = tempHero;
            }
        }
    }
}
// print info
void printHeroHandle(GameHero heros[], int count)
{
    // 打印所有排序后的信息
    for (int i = 0; i < count; i++)
    {
        GameHero hero = heros[i];
        cout <<"姓名："<< hero.sName<<"\t年龄："<<hero.age<<"\t性别："<<hero.gender<<endl;
    }
}
// todo: public method
void sortGameHeroAction()
{
    // 构建游戏英雄信息
    GameHero heros[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂婵", 19, "女"}
    };
    // sort
    int count = sizeof(heros)/sizeof(heros[0]);
    sortHeroHandle(heros, count);
    // print
    printHeroHandle(heros, count);
}
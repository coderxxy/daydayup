#include <iostream>
using namespace std;

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
    // 学生数组
    Student sArray[5];
};

/// gameHero
struct GameHero
{
    string sName;       // 姓名
    int age;            // 年龄
    string gender;      // 性别
};

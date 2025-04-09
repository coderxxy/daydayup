#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    /* data */
public:

    string m_name;          // 名称
    float m_weight;        // 体重

    Animal(/* args */);
    Animal(string name, float weight);
    ~Animal();
};

#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
private:
    /* data */
public:
    virtual int getResult() = 0;
    int num1;
    int num2;
};

// TODO: AddCalculator
class AddCalculator : public AbstractCalculator
{
private:
    /* data */
public:
    int getResult()
    {
        return (this->num1 + this->num2);
    }
};

//
class SubCalculator : public AbstractCalculator
{
private:
    /* data */
public:
    int getResult()
    {
        return (num1 - num2);
    }

};

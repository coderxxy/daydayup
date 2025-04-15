#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class FileOperater
{
private:
    /* data */
public:
    FileOperater(/* args */);
    ~FileOperater();

    void fileRWHandle();
    void fileRWBinary();
};


void fileOperationHandle();
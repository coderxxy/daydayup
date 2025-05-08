#include "Otherknowledge.h"

Otherknowledge::Otherknowledge(/* args */)
{
}

Otherknowledge::~Otherknowledge()
{
}

// TODO: 函数模版
template<typename T>
void swapValue(T& A, T& B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T>
void func()
{
    std::cout<<"func 调用"<<std::endl;
}
// TODO: 实现通用 数组进行排序的函数，选择排序 从大到小， 测试 char、int
template<class T>
void arraySort(T arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int max = i; // 认定最大值下标
        for (int j = i + 1; j < length; j++)
        {
            // 认定的最大值 比 遍历的数值 小， 说明 j 下标的元素才是真正的最大值
            if (arr[max] < arr[j])
            {
                max = j; // 更新最大值下标
            }
        }
        // 交换最大值
        if (max != i)
        {
            swapValue(arr[max], arr[i]);
        }
    }
}

template<class T>
void printArray (T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void Otherknowledge::templateTest()
{
    int a = 10;
    int b = 20;
    // 1、自动类型推导 注意：类型一致
    swapValue(a, b);
    
    // 2、显示指定类型 注意：明确的类型
    // swapValue<int>(a, b); 
    cout<<"a:"<<a<<"\tb:"<<b<<endl;

    func<void>();

    //
    char charArr[] = "badcfe";
    int len = sizeof(charArr)/sizeof(char);
    arraySort<char>(charArr, len);
    //
    printArray(charArr, len);


    int arr[] = {1, 23, 3, 5, 7};
    int len1 = sizeof(arr)/sizeof(int);
    arraySort<int>(arr, len1);
    //
    printArray(arr, len1);
}
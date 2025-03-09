#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "functions.h"
#include "structs.h"
#include "contactsSystemManager.h"

///// @brief 猜字游戏
//void playGameAction();
//// 水仙花 所有三位数
//void daffodilHandle();
//// 敲桌子 0-100范围内，数字中带7，7的倍数
//void clickDeskGame();
//// 乘法表
//void multiplicationTable();
//// 元素逆置
//void reverseHandle();
//// 冒泡排序 (升序)
//void sortHandle();
//// 值交换
//void swapHandle (int a, int b);

int main(int argc, char const *argv[])
{
    // cout <<"hello world!\n"<<endl;
    // int a = 10;
    // unsigned long length = sizeof(a);
    // cout <<"数据类型所占内存大小：\n"<<length<<endl;

    // playGameAction();
    // daffodilHandle();
    // clickDeskGame();
    // multiplicationTable();
    // reverseHandle();
    // sortHandle();
//    swapHandle(10, 20);

//    structArrayHandle();
//structPointHandle();
// structWithStructHandle();

// teacherInfoAction();
// sortGameHeroAction();

contactsSystemManagerAction();

    // system("pause");
    

    return 0;
}


//// TODO: 猜字游戏
//void playGameAction()
//{
//    // 添加随机数种子，利用当前系统时间生成随机数，防止随机数重复
//    unsigned int second = time(NULL);
//    srand(second);
//    // 1到100随机数
//    int randomNum = rand()%100+1;
//    cout <<"随机数:"<<randomNum<<"\n"<<endl;
//    cout<<"猜数游戏😊,随便输入0～100间的数字\n"<<endl;
//    int val = 0; // 输入数字
//
//    int errCount = 0;
//    int maxCount = 5;
//
//    while (1)
//    {
//        cin >> val;
//        if (val > randomNum)
//        {
//            cout<<"过大\n"<<endl;
//            errCount ++;
//            cout <<"猜错了"<<errCount<<"次\n"<<endl;
//            if (maxCount != errCount)
//            {
//                cout<<"还剩"<<maxCount-errCount<<"次机会\n"<<endl;
//            }
//        }
//        else if (val < randomNum)
//        {
//            cout <<"太小\n"<<endl;
//            errCount ++;
//            cout <<"猜错了"<<errCount<<"次\n"<<endl;
//            if (maxCount != errCount)
//            {
//                cout<<"还剩"<<maxCount-errCount<<"次机会\n"<<endl;
//            }
//        }
//        else
//        {
//            cout<< "恭喜你🎉\n" <<endl;
//            break;
//        }
//
//        if (errCount >= maxCount)
//        {
//            cout <<"很遗憾，你太笨了！😂\n"<<endl;
//            cout <<"数字是"<<randomNum<<endl;
//            errCount = 0;
//            break;
//        }
//
//    }
//}
//// 水仙花 所有三位数
//void daffodilHandle()
//{
//    int num = 100;
//    do
//    {
//        int a, b ,c = 0;
//        a = num%10;
//        b = (num/10)%10;
//        c = num/100;
//        if (a*a*a + b*b*b + c*c*c == num)
//        {
//            cout <<"水仙花数："<< num <<"\n"<<endl;
//
//            cout <<"个位："<<a<<"，三次幂："<<(a*a*a)<<"\n"<<endl;
//            cout <<"十位："<<b<<"，三次幂："<<(b*b*b)<<"\n"<<endl;
//            cout <<"百位："<<c<<"，三次幂："<<(c*c*c)<<"\n"<<endl;
//        }
//        num ++;
//    }while (num<1000);
//}
//// 敲桌子 0-100范围内，数字中带7，7的倍数
//void clickDeskGame()
//{
//    int num = 0;
//    do
//    {
//        int a, b, c = 0;
//        a = num%10;
//        b = num/10%10;
//        // c = num/100;
//        if (num < 10 && num != 0 && num%7 == 0)
//        {
//            cout<<num<<"\t敲桌子\n"<<endl;
//        }
//        else if (num < 100 && num >= 10 && ((a==7 || b==7 || num%7==0)))
//        {
//            cout<<num<<"\t敲桌子\n"<<endl;
//        }
//        else
//        {
//            cout<<num<<"\n"<<endl;
//        }
//        num ++;
//    } while (num<=100);
//}
//// 乘法表
//void multiplicationTable()
//{
//    for (int row = 1; row <= 9; row++)
//    {
//        for (int column = 1; column <= row; column++)
//        {
//            cout<<column<<"*"<<row<<"="<<column*row<<"\t";
//        }
//        cout <<"\n"<<endl;
//    }
//}
//// 元素逆置
//void reverseHandle()
//{
//    int arr[] = {1, 3, 2, 5, 4, 6};
//    int temp = 0;
//    int count = sizeof(arr)/sizeof(arr[0]);
//    cout <<"重置前"<< endl;
//    for (int i = 0; i < count; i++)
//    {
//        cout<<arr[i]<< " ";
//    }
//    for (int i = 0; i < count; i++)
//    {
//        if (i == count/2) break;
//        temp = arr[i];
//        arr[i] = arr[count-1-i];
//        arr[count-1-i]=temp;
//    }
//    cout <<"\n重置后"<< endl;
//    for (int i = 0; i < count; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
//// 冒泡排序 (升序)
//void sortHandle()
//{
//    int arr [] = {4,2,8,0,5,7,1,3,9};
//    int count = sizeof(arr)/sizeof(arr[0]);
//    int temp = 0;
//    for (int i = 0; i < count; i++)
//    {
//        for (int j = i+1; j < count; j++)
//        {
//           if (arr[i] > arr[j])
//           {
//            temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//           }
//        }
//    }
//
//    cout <<"\n排序后"<< endl;
//    for (int i = 0; i < count; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
//// 冒泡排序
//void bubbleSort (int *arr, int length)
//{
//    for (int i = 0; i < length-1; i++)
//    {
//        for (int j = 0; i < length-i-1; j++)
//        {
//            if (arr[j] > arr[j+1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//        }
//    }
//}
//// 值交换 【值传递】
//void swapHandle (int a, int b)
//{
//    cout <<"交换前 a:"<<a<<endl;
//    cout <<"交换前 b:"<<b<<endl;
//    int sum = a + b;
//    a = sum - a;
//    b = sum - a;
//    cout <<"交换后 a:"<<a<<endl;
//    cout <<"交换后 b:"<<b<<endl;
//}
//// 数字交换 【地址传递】
//void swapPointHandle(int *a, int *b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}

// 获取个位     n%10
// 获取十位     n/10
// 获取百位     n/100
#include "functions.h"
#include <string>
#include <ctime>

// TODO: 猜字游戏
void playGameAction()
{
    // 添加随机数种子，利用当前系统时间生成随机数，防止随机数重复
    unsigned int second = time(NULL);
    srand(second);
    // 1到100随机数
    int randomNum = rand()%100+1; 
    cout <<"随机数:"<<randomNum<<"\n"<<endl;
    cout<<"猜数游戏😊,随便输入0～100间的数字"<<endl;
    int val = 0; // 输入数字

    int errCount = 0;
    int maxCount = 5;

    while (1)
    {
        cin >> val;
        if (val > randomNum)
        {
            cout<<"过大\n"<<endl;
            errCount ++;
            cout <<"猜错了"<<errCount<<"次\n"<<endl;
            if (maxCount != errCount)
            {
                cout<<"还剩"<<maxCount-errCount<<"次机会\n"<<endl;
            }
        }
        else if (val < randomNum)
        {
            cout <<"太小\n"<<endl;
            errCount ++;
            cout <<"猜错了"<<errCount<<"次\n"<<endl;
            if (maxCount != errCount)
            {
                cout<<"还剩"<<maxCount-errCount<<"次机会\n"<<endl;
            }
        }
        else
        {
            cout<< "恭喜你🎉\n" <<endl;
            break;
        }

        if (errCount >= maxCount)
        {
            cout <<"很遗憾，你太笨了！😂\n"<<endl;
            cout <<"数字是"<<randomNum<<endl;
            errCount = 0;
            break;
        }
        
    }
}
// 水仙花 所有三位数
void daffodilHandle()
{
    int num = 100;
    do
    {
        int a, b ,c = 0;
        a = num%10;
        b = (num/10)%10;
        c = num/100;
        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout <<"水仙花数："<< num <<"\n"<<endl;

            cout <<"个位："<<a<<"，三次幂："<<(a*a*a)<<"\n"<<endl;
            cout <<"十位："<<b<<"，三次幂："<<(b*b*b)<<"\n"<<endl;
            cout <<"百位："<<c<<"，三次幂："<<(c*c*c)<<"\n"<<endl;
        }
        num ++;
    }while (num<1000);
}
// 敲桌子 0-100范围内，数字中带7，7的倍数
void clickDeskGame()
{
    int num = 0;
    do
    {
        int a, b, c = 0;
        a = num%10;
        b = num/10%10;
        // c = num/100;
        if (num < 10 && num != 0 && num%7 == 0)
        {
            cout<<num<<"\t敲桌子\n"<<endl;
        }
        else if (num < 100 && num >= 10 && ((a==7 || b==7 || num%7==0)))
        {
            cout<<num<<"\t敲桌子\n"<<endl;
        }
        else
        {
            cout<<num<<"\n"<<endl;
        }
        num ++;
    } while (num<=100);
}
// 乘法表
void multiplicationTable()
{
    for (int row = 1; row <= 9; row++)
    {
        for (int column = 1; column <= row; column++)
        {
            cout<<column<<"*"<<row<<"="<<column*row<<"\t";
        }
        cout <<"\n"<<endl;
    }
}
// 元素逆置
void reverseHandle()
{
    int arr[] = {1, 3, 2, 5, 4, 6};
    int temp = 0;
    int count = sizeof(arr)/sizeof(arr[0]);
    cout <<"重置前"<< endl;
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<< " ";
    }
    for (int i = 0; i < count; i++)
    {
        if (i == count/2) break;
        temp = arr[i];
        arr[i] = arr[count-1-i];
        arr[count-1-i]=temp;
    }
    cout <<"\n重置后"<< endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}
// 冒泡排序 (升序)
void sortHandle()
{
    int arr [] = {4,2,8,0,5,7,1,3,9};
    int count = sizeof(arr)/sizeof(arr[0]);
    int temp = 0;
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
           if (arr[j] > arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
           }
        }
    }

    cout <<"\n排序后"<< endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}
// 值交换
void swapHandle (int a, int b)
{
    cout <<"交换前 a:"<<a<<endl;
    cout <<"交换前 b:"<<b<<endl;
    int sum = a + b;
    a = sum - a;
    b = sum - a;
    cout <<"交换后 a:"<<a<<endl;
    cout <<"交换后 b:"<<b<<endl;
}

#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#define max 1000
using namespace std;
int main() {

    int N,carry,i,j,x,len;
    cout<<("Enter the number you want to calculate = ");
    cin>>N;//输入我们想进行阶乘运算的数
    int t[max];//我们在这里定义一个数组来进行阶乘运算
    memset(t,0,sizeof(t));//置空数组
    t[0] = 1;
    len = 1;

    carry = 0;

    for(i=1;i<=N;i++)
    {
        for(j=0;j<len;j++)  //此处的for循环是此前数组之前数相乘的变形，此处使用整型i来代替另一个数组。
        {
            x = t[j]*i + carry;
            t[j] = x%10;
            carry = x/10;
        }
        while(carry>0) //此处的carry用来判断相乘的结果是否大于10，用于对数组该处的大于10的数进位。
        {
            t[len] = carry%10;
            carry = carry/10;
            len++;
        }
    }

    for(i=len-1;i>=0;i--)
       cout<<t[i];//输出结果
    return 0;
}

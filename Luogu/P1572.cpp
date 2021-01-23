#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
long long a[100], b[100], s[100];
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    string str;
    cin >> str;
    if (isdigit(str[0]))
    {
        str.insert(0, 1, '+');
    }
    str.append("@");         //防越界
    int p = 0, i = 0, n = 0; //p最后一组数据位置
    memset(s, -1, sizeof(s));
    while (str[i] != '@')
    {
        p++;
        int sign = 1;
        if (str[i] == '+') //判断符号
        {
            s[p] = 1;
        }
        i++, n = 0;
        while (isdigit(str[i])) //统计分子
        {
            n = n * 10 + (str[i] - '0');
            i++;
        }
        a[p] = n;
        i++, n = 0;
        while (isdigit(str[i])) //统计分母
        {
            n = n * 10 + (str[i] - '0');
            i++;
        }
        b[p] = n;
        int r = gcd(a[p], b[p]); //约分
        a[p] /= r;
        b[p] /= r;
    }
    for (int i = 2; i <= p; i++)
    {
        int r = gcd(b[1], b[i]);
        a[1] = s[1] * a[1] * (b[i] / r) + s[i] * a[i] * (b[1] / r); //计算分子
        b[1] = b[1] / r * b[i];                                     //统一分母
        if (a[1] < 0)                                               //更新符号
        {
            a[1] *= -1;
            s[1] = -1;
        }
        else
        {
            s[1] = 1;
        }
        r = gcd(a[1], b[1]); //约分
        a[1] /= r;
        b[1] /= r;
    }
    if (s[1] == -1)
    {
        cout << '-';
    }
    cout << a[1];
    if (b[1] != 1)
    {
        cout << "/" << b[1];
    }
    return 0;
}
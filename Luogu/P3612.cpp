#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    long long n;
    cin >> str >> n;
    long long len = str.size();
    while (n > len) //* 递推 找到n是每个字符串中的第几个字符
    {
        long long sz = len;
        while (sz < n)
        {
            sz *= 2;
        }
        //* 逆推n在之前一个字符串中的位置 n = n - sz/2
        //* 因为总是先复制前一个字符串的最后一个字符 所以再 -1
        n = n - sz / 2 - 1;
        //* 如果n的结果是0 说明n是先复制的上次的最后一个字符
        if (n == 0)
        {
            n = sz / 2;
        }
    }
    cout << str[n - 1];
    return 0;
}
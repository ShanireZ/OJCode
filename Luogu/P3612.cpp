#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    long long n;
    cin >> str >> n;
    long long len = str.size();
    while (n > len) //* 遞推 找到n是每個字串中的第幾個字元
    {
        long long sz = len;
        while (sz < n)
        {
            sz *= 2;
        }
        //* 逆推n在之前一個字串中的位置 n = n - sz/2
        //* 因為總是先複製前一個字串的最後一個字元 所以再 -1
        n = n - sz / 2 - 1;
        //* 如果n的結果是0 說明n是先複製的上次的最後一個字元
        if (n == 0)
        {
            n = sz / 2;
        }
    }
    cout << str[n - 1];
    return 0;
}
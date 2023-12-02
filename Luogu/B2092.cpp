#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int d[5005]; //! 0表示开启 1表示关闭
int main()
{
    memset(d, 0, sizeof(d));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //! 人的编号
    {
        for (int j = i; j <= n; j += i) //! 灯的编号
        {
            if (d[j] == 0)
            {
                d[j] = 1;
            }
            else
            {
                d[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}
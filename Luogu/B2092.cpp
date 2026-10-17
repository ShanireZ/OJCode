#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int d[5005]; //! 0表示開啟 1表示關閉
int main()
{
    memset(d, 0, sizeof(d));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //! 人的編號
    {
        for (int j = i; j <= n; j += i) //! 燈的編號
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
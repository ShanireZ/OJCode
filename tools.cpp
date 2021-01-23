#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //int a[10] = {5, 7, 9, 0, 3, 1, 8, 2, 4, 6};
    int a[10] = {7, 3, 6, 8, 9, 5, 1, 2, 4, 10};
    //默认从小到大 less<>() 从大到小 greater<>()
    sort(a + 0, a + 0 + 10, greater<int>());

    // for (int i = 0; i < 10; i++) //选择排序
    // {
    //     int pos = 0;
    //     for (int j = 0; j < 10; j++)
    //     {
    //         if (a[j] > a[pos])
    //         {
    //             pos = j;
    //         }
    //     }
    //     swap(a[i], a[pos]);
    // }

    // for (int i = 9; i >= 0; i--) //冒泡排序
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (a[j] > a[j + 1])
    //         {
    //             swap(a[j], a[j + 1]);
    //         }
    //     }
    // }

    // for (int i = 0; i < 10; i++) //插入排序
    // {
    //     for (int j = i; j >= 1; j--)
    //     {
    //         if (a[j - 1] > a[j])
    //         {
    //             swap(a[j - 1], a[j]);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }

    return 0;
}

#include <cstdio>
using namespace std;


int read();
int main()
{

}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}
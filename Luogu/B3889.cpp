#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, s, m;
    scanf("%d %d %d", &n, &s, &m);
    int a = n - m;
    for (int i = 0; i <= m; i++) // 枚舉一半分個數c
    {
        for (int j = 0; j <= a; j++) // 枚舉附加分個數b
        {
            int now = a * 1e7 / n + j + i * 1e7 / n / 2;
            if (now == s)
            {
                printf("p%d(+%d) f%d l%d", a, j, i, m - i);
                return 0;
            }
        }
    }
    return 0;
}
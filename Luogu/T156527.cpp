#include <cstdio>
#include <cmath>
using namespace std;
int read();
int main()
{
    int c = read();
    for (int a = 1; a <= 15000; a++)
    {
        int b = sqrt(c * c - a * a);
        if (a * a + b * b == c * c)
        {
            printf("%d %d", a, b);
            return 0;
        }
    }
    return 0;
}
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
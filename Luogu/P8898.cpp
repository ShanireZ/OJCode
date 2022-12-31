#include <iostream>
using namespace std;
int read();
char grass[100005];
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            grass[i] = '.';
        }
        int h = 0, g = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            scanf("%c", &ch);
            int pos = min(i + k, n);
            pos -= (grass[pos] != '.');
            if (ch == 'H' && i > h)
            {
                grass[pos] = 'H', h = i + k * 2, cnt++;
            }
            else if (ch == 'G' && i > g)
            {
                grass[pos] = 'G', g = i + k * 2, cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++)
        {
            printf("%c", grass[i]);
        }
        printf("\n");
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
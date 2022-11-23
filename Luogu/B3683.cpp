#include <cstring>
#include <iostream>
using namespace std;
#define MX 1000005
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
char s[MX], t[MX];
int pos[MX], n, q;
int main()
{
    int T = read();
    while (T--)
    {
        memset(pos, 0, sizeof(pos));
        n = read(), q = read();
        int cnt = 0;
        scanf("%s %s", s, t);
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                pos[i] = 1, cnt++;
            }
        }
        !cnt ? printf("Yes\n") : printf("No\n");
        for (int i = 1; i <= q; i++)
        {
            int o = read(), p = read();
            char c = getchar();
            !o ? s[p - 1] = c : t[p - 1] = c;
            if (s[p - 1] == t[p - 1] && pos[p - 1] == 1)
            {
                pos[p - 1] = 0, cnt--;
            }
            else if (s[p - 1] != t[p - 1] && pos[p - 1] == 0)
            {
                pos[p - 1] = 1, cnt++;
            }
            !cnt ? printf("Yes\n") : printf("No\n");
        }
    }
    return 0;
}
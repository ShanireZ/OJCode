#include <iostream>
using namespace std;
char f[1000005];
int main()
{
    int n, m, cnt = 0;
    scanf("%d %d %s", &n, &m, f + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        if (f[a - cnt] == '1')
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
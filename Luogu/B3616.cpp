#include <iostream>
using namespace std;
int p[10005], st = 1, ed = 0, n;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &p[++ed]);
        }
        else if (opt == 2)
        {
            if (st > ed)
            {
                printf("ERR_CANNOT_POP\n");
            }
            else
            {
                st++;
            }
        }
        else if (opt == 3)
        {
            if (st > ed)
            {
                printf("ERR_CANNOT_QUERY\n");
            }
            else
            {
                printf("%d\n", p[st]);
            }
        }
        else
        {
            printf("%d\n", ed - st + 1);
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
string s;
bool prim[100000005];
int all[10000005], nums[13], a, b, apos;
bool check(int x)
{
    int pos = 0;
    while (x)
    {
        nums[++pos] = x % 10;
        x /= 10;
    }
    for (int n = 1, m = pos; n <= m; n++, m--)
    {
        if (nums[n] != nums[m])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d", &a, &b);
    prim[0] = 1, prim[1] = 1;
    for (int i = 2; i <= b; i++)
    {
        if (prim[i] == 0)
        {
            all[++apos] = i;
        }
        for (int j = 1; all[j] * i <= b; j++)
        {
            prim[all[j] * i] = 1;
            if (i % all[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= apos; i++)
    {
        if (all[i] >= a && check(all[i]))
        {
            printf("%d\n", all[i]);
        }
    }
    return 0;
}
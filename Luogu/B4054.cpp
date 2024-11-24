#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0, p = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k, d, a, pw = 0;
        scanf("%d/%d/%d", &k, &d, &a);
        if (k - d >= 10)
        {
            pw = k * (k - d) + a;
        }
        else if (k >= d)
        {
            pw = (k - d + 1) * 3 + a;
        }
        else
        {
            pw = a * 2;
        }
        if (pw > p)
        {
            p = pw, ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
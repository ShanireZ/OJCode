#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n, k, ans[15];
    scanf("%d %d", &n, &k);
    int tot = pow(10, n - 1) * 9;
    int x = tot / k, y = tot % k, st = tot / 9 % k + 1;
    for (int i = 1; i <= k; i++)
    {
        ans[i] = x;
    }
    for (int i = 1; i <= y; i++)
    {
        ans[st]++;
        st = (st + 1 > k) ? 1 : st + 1;
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
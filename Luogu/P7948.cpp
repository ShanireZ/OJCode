#include <cstdio>
#include <algorithm>
using namespace std;
long long read();
long long nums[100005], k[100005], qz[100005];
int main()
{
    int t = read();
    while (t)
    {
        t--;
        int n = read(), q = read();
        for (int i = 1; i <= n; i++)
        {
            nums[i] = read();
        }
        for (int i = 1; i <= q; i++)
        {
            k[i] = read();
        }
        sort(nums + 1, nums + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            qz[i] = qz[i - 1] + nums[i];
        }
        for (int i = 1; i <= q; i++)
        {
            long long avg = qz[n] / n - k[i];
            if (qz[n] % n != 0)
            {
                avg++;
            }
            int p = lower_bound(nums + 1, nums + 1 + n, avg) - nums;
            int pre = 1;
            while (p != pre)
            {
                pre = p;
                avg = (qz[n] - qz[p - 1]) / (n - p + 1) - k[i];
                if ((qz[n] - qz[p - 1]) % (n - p + 1) % n != 0)
                {
                    avg++;
                }
                p = lower_bound(nums + 1, nums + 1 + n, avg) - nums;
            }
            printf("%d ", n - p + 1);
        }
        printf("\n");
    }
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
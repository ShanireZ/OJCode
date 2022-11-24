#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int read(), n, q;
vector<int> bs;
int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        bs.push_back(read());
    }
    sort(bs.begin(), bs.end(), greater<int>());
    for (int i = 1; i <= q; i++)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            printf("%d\n", bs[x - 1]);
        }
        else
        {
            auto pos = lower_bound(bs.begin(), bs.end(), x, greater<int>());
            bs.insert(pos, x);
        }
    }
    return 0;
}
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
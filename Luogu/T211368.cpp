#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
int vis[105];
vector<int> all;
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (vis[x] == 0)
        {
            vis[x] = 1;
            all.push_back(x);
        }
    }
    for (int i = 0; i < all.size(); i++)
    {
        printf("%d ", all[i]);
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
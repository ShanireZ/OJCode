#include <iostream>
#include <unordered_map>
using namespace std;
long long n, res, a[15], k[15];
unordered_map<long long, int> check;
void dfs(int now)
{
    if (now > n)
    {
        long long ans = 0;
        for (int i = 1; i <= n && k[i]; i++)
        {
            ans ^= k[i];
        }
        if (check[ans] == 0)
        {
            res++, check[ans] = 1;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        k[i] += a[now], dfs(now + 1), k[i] -= a[now];
        if (k[i] == 0) // 此位置是从0开始开荒的,后方开荒也一样的情况
        {
            break;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << res << endl;
    return 0;
}
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
using namespace std;
int prim[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, rec[100005];
map<int, long long> mp;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < 10; j++)
        {
            while (a % prim[j] == 0)
            {
                a /= prim[j], rec[i] ^= (1 << j);
            }
        }
    }
    int now = 0;
    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        now ^= rec[i];
        ans += mp[now];
        mp[now] += 1;
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int cnt[1005];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cnt[x]++;
        x = (x * 37 + 33031) % n + 1;
    }
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > cnt[pos])
        {
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}
// TAG: 模拟 贪心
#include <iostream>
using namespace std;
#define MX 5000005
int r[MX], c[MX], n, m, k, cnt;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        char op;
        int x;
        cin >> op >> x;
        (op == 'R') ? (r[x] = (r[x] + 1) % 2) : (c[x] = (c[x] + 1) % 2);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cnt += (r[i] ^ c[j]);
        }
    }
    cout << cnt << "\n";
    return 0;
}
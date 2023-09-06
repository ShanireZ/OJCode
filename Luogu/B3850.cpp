#include <algorithm>
#include <iostream>
using namespace std;
int ans[10];
int main()
{
    for (int i = 1; i < 10; i++)
    {
        int x = i * 7;
        while (x > 9)
        {
            int tot = 0;
            while (x)
            {
                tot += x % 10, x /= 10;
            }
            x = tot;
        }
        ans[i] = x;
    }
    int n;
    cin >> n;
    while (n--) // 很容易看错题
    {
        long long x, tot = 0, pos = 0;
        cin >> x;
        while (x)
        {
            if (++pos % 2 == 1)
            {
                tot += ans[x % 10];
            }
            else
            {
                tot += x % 10;
            }
            x /= 10;
        }
        if (tot % 8 == 0)
        {
            cout << 'T' << endl;
        }
        else
        {
            cout << 'F' << endl;
        }
    }
    return 0;
}
// TAG: 模拟
#include <iostream>
#include <cstring>
using namespace std;
int num[5005];
void multi(int x)
{
    int last = 0, p = 0;
    for (int i = 0; i < 5000 && num[i] != -1; i++)
    {
        num[i] = num[i] * x + last;
        last = num[i] / 10;
        num[i] %= 10;
        p = i + 1;
    }
    while (last)
    {
        num[p] = last % 10;
        last /= 10;
        p++;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(num, -1, sizeof(num));
        int ans = 0;
        num[0] = 1;
        int n, a;
        cin >> n >> a;
        for (int i = 2; i <= n; i++)
        {
            multi(i);
        }
        for (int i = 0; i < 5000 && num[i] != -1; i++)
        {
            if (num[i] == a)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int cnt[100005];
int main()
{
    int n, zd = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        if (zd < x)
        {
            zd = x;
        }
    }
    for (int i = 0; i <= zd; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}
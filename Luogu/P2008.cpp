#include <algorithm>
#include <iostream>
using namespace std;
int a[10005], len[10005], res[10005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j])
            {
                if (len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1, res[i] = a[i] + res[j];
                }
            }
        }
        cout << res[i] << " ";
    }
    return 0;
}
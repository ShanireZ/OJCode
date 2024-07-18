#include <algorithm>
#include <iostream>
using namespace std;
int prim[1000005], cnt[1000005];
int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (prim[i] == 0)
        {
            for (int j = i; j <= 1000000; j += i)
            {
                prim[j] = 1, cnt[j]++;
            }
        }
    }
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << (cnt[x] == 2 ? 1 : 0) << endl;
    }
    return 0;
}
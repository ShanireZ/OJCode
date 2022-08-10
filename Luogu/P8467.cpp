#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[7] = {-1};
        for (int i = 1; i <= 4; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 5);
        int same = -1, c = 0, ans = 0;
        for (int i = 1; i <= 2; i++)
        {
            if (a[i] == a[i + 1] - 1 && a[i + 1] == a[i + 2] - 1)
            {
                ans = 1;
            }
        }
        for (int i = 1; i <= 4; i++)
        {
            if (a[i] == a[i - 1])
            {
                same = i;
            }
        }
        for (int i = 1; i <= 4; i++)
        {
            if (i != same && i != same - 1)
            {
                c = a[i] - c;
            }
        }
        if ((c == 1 || c == 2) && same != -1)
        {
            ans = 1;
        }
        if (ans)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
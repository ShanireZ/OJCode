#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    memset(a, 0, sizeof(a));
    for (i = n; i >= 0; i--)//读入
    {
        cin >> a[i];
    }
    if (a[n] > 1 || a[n] < -1) //i = n
    {
        cout << a[n] << "x^" << n;
    }
    else if (a[n] == 1)
    {
        cout << "x^" << n;
    }
    else if (a[n] == -1)
    {
        cout << "-x^" << n;
    }
    for (i = n - 1; i > 1; i--) //i = n - 1  ~  i = 2
    {
        if (a[i] > 1)
        {
            cout << '+' << a[i] << "x^" << i;
        }
        else if (a[i] < -1)
        {
            cout << a[i] << "x^" << i;
        }
        else if (a[i] == 1)
        {
            cout << '+' << "x^" << i;
        }
        else if (a[i] == -1)
        {
            cout << '-' << "x^" << i;
        }
    }
    if (a[1] > 1) //i = 1
    {
        cout << '+' << a[i] << 'x';
    }
    else if (a[i] < -1)
    {
        cout << a[i] << 'x';
    }
    else if (a[i] == 1)
    {
        cout << '+' << 'x';
    }
    else if (a[i] == -1)
    {
        cout << '-' << 'x';
    }
    if (a[0] > 0) //i = 0
    {
        cout << '+' << a[0];
    }
    else if (a[0] < 0)
    {
        cout << a[0];
    }
    return 0;
}
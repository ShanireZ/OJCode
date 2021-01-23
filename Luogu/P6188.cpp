#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t = n / 14;
    n %= 14;
    if (n == 1 || n == 2 || n == 5)
    {
        t--;
        n += 14;
    }
    if (t < 0)
    {
        cout << -1;
        return 0;
    }
    if (n == 0)
    {
        cout << t << " " << t << " " << t;
    }
    else if (n == 3)
    {
        cout << t << " " << t << " " << t + 1;
    }
    else if (n == 4)
    {
        cout << t << " " << t + 1 << " " << t;
    }
    else if (n == 6)
    {
        cout << t << " " << t << " " << t + 2;
    }
    else if (n == 7)
    {
        cout << t << " " << t + 1 << " " << t + 1;
    }
    else if (n == 8)
    {
        cout << t << " " << t + 2 << " " << t;
    }
    else if (n == 9)
    {
        cout << t << " " << t << " " << t + 3;
    }
    else if (n == 10)
    {
        cout << t << " " << t + 1 << " " << t + 2;
    }
    else if (n == 11)
    {
        cout << t << " " << t + 2 << " " << t + 1;
    }
    else if (n == 12)
    {
        cout << t << " " << t << " " << t + 4;
    }
    else if (n == 13)
    {
        cout << t << " " << t + 1 << " " << t + 3;
    }
    else if (n == 15)
    {
        cout << t << " " << t << " " << t + 5;
    }
    else if (n == 16)
    {
        cout << t << " " << t + 1 << " " << t + 4;
    }
    else if (n == 19)
    {
        cout << t << " " << t + 1 << " " << t + 5;
    }
    return 0;
}
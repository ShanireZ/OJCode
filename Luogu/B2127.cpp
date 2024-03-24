#include <algorithm>
#include <iostream>
using namespace std;
bool check(int x)
{
    int tot = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            tot += i;
            if (x / i != i)
            {
                tot += x / i;
            }
        }
    }
    if (tot == x)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (check(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int count()
{
    int a, da, x = 0;
    cin >> a >> da;
    while (a)
    {
        if (a % 10 == da)
        {
            x = x * 10 + da;
        }
        a /= 10;
    }
    return x;
}
int main()
{
    cout << count() + count();
    return 0;
}
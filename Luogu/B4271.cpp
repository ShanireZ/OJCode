#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        int sum = 0, x = i;
        while (x)
        {
            sum += (x % 10) * (x % 10) * (x % 10) * (x % 10);
            x /= 10;
        }
        if (sum == i)
        {
            cout << i << " ";
        }
    }
    return 0;
}
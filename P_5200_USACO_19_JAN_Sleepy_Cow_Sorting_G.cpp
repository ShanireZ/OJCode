#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int rk[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> rk[i];
    }
    int step = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (rk[i] > rk[i + 1])
        {
            step = i + 1;
            break;
        }
    }
    cout << step;
    return 0;
}
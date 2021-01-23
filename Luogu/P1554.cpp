#include <iostream>
using namespace std;
int t[10];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        int x = i;
        while (x != 0)
        {
            t[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}
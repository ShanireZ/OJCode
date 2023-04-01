#include <iostream>
using namespace std;
int nums[105];
int main()
{
    int n, m;
    cin >> n >> m;
    m %= n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = n - m + 1; i <= n; i++)
    {
        cout << nums[i] << " ";
    }
    for (int i = 1; i <= n - m; i++)
    {
        cout << nums[i];
        if (i != n - m)
        {
            cout << " ";
        }
    }
    return 0;
}
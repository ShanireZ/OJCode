#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0, total = 0, num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (total + num > m)
        {
            count++;
            total = num;
        }
        else
        {
            total += num;
        }
    }
    cout << count + 1;
    return 0;
}
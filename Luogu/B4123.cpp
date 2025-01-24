#include <algorithm>
#include <iostream>
using namespace std;
int rec[10005], pos, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t <= 15)
        {
            cout << t << " ";
        }
        else
        {
            rec[++pos] = t;
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        cout << rec[i] << " ";
    }
    return 0;
}
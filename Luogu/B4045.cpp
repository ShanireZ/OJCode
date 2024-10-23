#include <algorithm>
#include <iostream>
using namespace std;
int p[10005], n;
int main()
{
    cin >> n;
    n += n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[p[i]] != i || p[i] == i)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
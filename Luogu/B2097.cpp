#include <algorithm>
#include <iostream>
using namespace std;
int a[105];
int main()
{
    int n, c = 1, zc = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
        {
            c++;
        }
        else
        {
            c = 1;
        }
        if (c > zc)
        {
            zc = c;
        }
    }
    cout << zc << endl;
    return 0;
}
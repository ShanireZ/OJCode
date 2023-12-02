#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int ok[105];
int main()
{
    memset(ok, 0, sizeof(ok));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (ok[a] == 0)
        {
            cout << a << " ";
            ok[a] = 1;
        }
    }
    return 0;
}
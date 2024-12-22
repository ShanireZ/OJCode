#include <algorithm>
#include <iostream>
using namespace std;
int s[10005];
int main()
{
    int n, c;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n);
    cin >> c;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == c)
        {
            cout << n - i + 1 << endl;
            break;
        }
    }
    return 0;
}
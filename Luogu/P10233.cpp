#include <iostream>
#include <string>
using namespace std;
int a[10000005];
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, pos = 0;
        cin >> s >> n;
        for (char c : s)
        {
            pos++;
            a[pos] = a[pos - 1];
            if (c == 'P')
            {
                a[pos] += 3;
            }
            else if (c == 'p')
            {
                a[pos] += 2;
            }
            else if (c == 'G')
            {
                a[pos] += 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << endl;
        }
    }
    return 0;
}
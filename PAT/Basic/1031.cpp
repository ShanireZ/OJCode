#include <iostream>
#include <string>
using namespace std;
string s, ans[200];
int p[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    int n, ok = 1, pos = 0;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int z = 0;
        for (int i = 0; i < 17; i++)
        {
            z += p[i] * (s[i] - '0');
        }
        if (check[z % 11] != s[17])
        {
            ok = 0, ans[++pos] = s;
        }
    }
    if (ok)
    {
        cout << "All passed";
    }
    else
    {
        for (int i = 1; i <= pos; i++)
        {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
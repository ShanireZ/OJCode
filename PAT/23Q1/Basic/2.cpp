#include <iostream>
#include <string>
using namespace std;
string s[105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int h, w, r, d;
    cin >> h >> w >> r >> d;
    for (int i = d + 1; i <= d + h; i++)
    {
        for (int j = r + 1; j <= r + w; j++)
        {
            if (i <= n && j <= m)
            {
                cout << s[i][j - 1];
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}
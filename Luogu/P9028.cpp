#include <iostream>
using namespace std;
int main()
{
    int n, r, s;
    cin >> n >> r >> s;
    while (n--)
    {
        int maxv = 0, minv = 100;
        for (int i = r; i >= 1; i--)
        {
            for (int j = 1; j <= s; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '#')
                {
                    maxv = max(maxv, i), minv = min(minv, i);
                }
            }
        }
        cout << maxv - minv << "\n";
    }
    return 0;
}
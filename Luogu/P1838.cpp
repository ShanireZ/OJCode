#include <algorithm>
#include <iostream>
using namespace std;
int p[10], ans[10][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};
int main()
{
    int n, t = 1;
    cin >> n;
    while (n)
    {
        t = (t == 1 ? 2 : 1);
        p[n % 10] = t;
        n /= 10;
    }
    for (int i = 0; i < 8; i++)
    {
        int ok = 1;
        for (int j = 0; j < 3; j++)
        {
            if (p[ans[i][j]] != t)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "xiaoa wins." << endl;
            return 0;
        }
    }
    t = (t == 1 ? 2 : 1);
    for (int i = 0; i < 8; i++)
    {
        int ok = 1;
        for (int j = 0; j < 3; j++)
        {
            if (p[ans[i][j]] != t)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "uim wins." << endl;
            return 0;
        }
    }
    cout << "drew." << endl;
    return 0;
}
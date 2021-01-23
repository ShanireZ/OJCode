#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int cnt = k;
    for (int i = 1; i <= n; i++)
    {
        string wd;
        cin >> wd;
        if (cnt + wd.size() <= k)
        {
            cout << " " << wd;
            cnt += wd.size();
        }
        else
        {
            if (i != 1)
            {
                cout << endl;
            }
            cout << wd;
            cnt = wd.size();
        }
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 4; i <= n; i++)
    {
        string s = to_string(i);
        if (s.find("44") != string::npos || s.find("77") != string::npos || i % 4 == 0 || i % 7 == 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
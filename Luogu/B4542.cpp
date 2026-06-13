#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int main()
{
    cin >> s >> t;
    for (int i = 1; i <= (int)s.size(); i++)
    {
        int cnt = 0;
        for (int p = 0; p + i - 1 < (int)s.size(); p++)
        {
            string now = s.substr(p, i);
            if (now.find(t) != string::npos)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
    }
    return 0;
}
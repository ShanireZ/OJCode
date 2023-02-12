#include <iostream>
#include <string>
using namespace std;
string a[10] = {"MOO", "OOO", "MOM", "OOM"};
int edit[10] = {0, 1, 1, 2}, q;
int main()
{
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int ans = -1;
        for (int i = 0; i < 4; i++)
        {
            if (s.find(a[i]) != string::npos)
            {
                ans = s.size() - 3 + edit[i];
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
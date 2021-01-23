#include <iostream>
#include <string>
using namespace std;
char all[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main()
{
    int from, to, tot = 0;
    string s, ans;
    cin >> from >> s >> to;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (s[i] == all[j])
            {
                tot = tot * from + j;
            }
        }
    }
    while (tot)
    {
        int id = tot % to;
        ans.insert(0, 1, all[id]);
        tot = tot / to;
    }
    cout << ans;
    return 0;
}
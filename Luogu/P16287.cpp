#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> s[25];
map<string, int> m;
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        s[(int)str.size()].push_back(str);
        m[str] = 1;
    }
    for (int i = 20; i > 1; i--)
    {
        for (string str : s[i])
        {
            for (int j = 0; j < (int)str.size(); j++)
            {
                if (j > 0 && str[j] == str[j - 1])
                {
                    continue;
                }
                string x = str.substr(0, j) + str.substr(j + 1);
                if (m[x])
                {
                    ans += 2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
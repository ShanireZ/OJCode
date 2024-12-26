#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
set<string> res;
map<string, int> ts;
string str;
int n, f;
int main()
{
    cin >> n >> f >> str;
    for (int i = 0; i + 2 < n; i++)
    {
        if (str[i] != str[i + 1] && str[i + 1] == str[i + 2])
        {
            string tmp = str.substr(i, 3);
            if (++ts[tmp] == f)
            {
                res.insert(tmp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char now = j + 'a';
            if (i + 2 < n && now != str[i + 1] && str[i + 1] == str[i + 2])
            {
                string tmp = now + str.substr(i + 1, 2);
                if (tmp == str.substr(i, 3) || (i > 0 && tmp == str.substr(i - 1, 3)) || (i > 1 && tmp == str.substr(i - 2, 3)))
                {
                    continue;
                }
                if (ts[tmp] + 1 >= f)
                {
                    res.insert(tmp);
                }
            }
            if (i > 0 && i + 1 < n && now == str[i + 1] && now != str[i - 1])
            {
                string tmp = str.substr(i - 1, 1) + now + str.substr(i + 1, 1);
                if ((i + 2 < n && tmp == str.substr(i, 3)) || (tmp == str.substr(i - 1, 3)) || (i > 1 && tmp == str.substr(i - 2, 3)))
                {
                    continue;
                }
                if (ts[tmp] + 1 >= f)
                {
                    res.insert(tmp);
                }
            }
            if (i > 1 && now == str[i - 1] && now != str[i - 2])
            {
                string tmp = str.substr(i - 2, 2) + now;
                if ((i + 2 < n && tmp == str.substr(i, 3)) || (i + 1 < n && tmp == str.substr(i - 1, 3)) || (tmp == str.substr(i - 2, 3)))
                {
                    continue;
                }
                if (ts[tmp] + 1 >= f)
                {
                    res.insert(tmp);
                }
            }
        }
    }
    cout << res.size() << endl;
    for (string x : res)
    {
        cout << x << endl;
    }
    return 0;
}
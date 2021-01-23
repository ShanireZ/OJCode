#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s, tmp;
string str1, str2;
int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        int max_size = 0;
        int m = min(s.size(), tmp.size());
        for (int j = 1; j <= m; j++)
        {
            str1 = s.substr(s.size() - j, j);
            str2 = tmp.substr(0, j);
            if (str1 == str2)
            {
                max_size = j;
            }
        }
        tmp.erase(0, max_size);
        s.append(tmp);
    }
    cout << s << endl;
    return 0;
}
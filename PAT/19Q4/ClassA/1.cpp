#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int start, trig;
string lts[30][10];
string ops[10];
string str;
int main()
{
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            cin >> lts[i][j];
        }
    }
    getchar();
    getline(cin, str);
    str += '!';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            trig = 1;
            for (int j = 1; j <= 7; j++)
            {
                ops[j].append(lts[str[i] - 'A' + 1][j]).append(" ");
            }
        }
        else if (trig)
        {
            if (start)
            {
                cout << endl
                     << endl;
            }
            for (int j = 1; j <= 7; j++)
            {
                ops[j].erase(ops[j].end() - 1, ops[j].end());
                cout << ops[j];
                if (j != 7)
                {
                    cout << endl;
                }
                ops[j].erase();
            }
            start = 1;
            trig = 0;
        }
    }
    return 0;
}
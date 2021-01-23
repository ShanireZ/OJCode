#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string encryption;
    string origin;
    string telegraph;
    cin >> encryption >> origin >> telegraph;
    if (origin.size() < 26) //密码不够，符合2
    {
        cout << "Failed";
        return 0;
    }
    char words[26];
    memset(words, 0, sizeof(words));
    for (int i = 0; i < origin.size(); i++) //读入密码本
    {
        if (words[origin[i] - 'A'] == 0)
        {
            words[origin[i] - 'A'] = encryption[i];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (words[i] == words[j] || words[i] == 0 || words[j] == 0) //密码不够或重复，符合2/3
            {
                cout << "Failed";
                return 0;
            }
        }
    }
    for (int i = 0; i < telegraph.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (words[j] == telegraph[i])
            {
                string str;
                str += ('A' + j);
                telegraph.replace(i, 1, str);
                break;
            }
        }
    }
    cout << telegraph;
    return 0;
}
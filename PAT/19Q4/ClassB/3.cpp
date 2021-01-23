#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int t;
    char ch;
};
Node all[10];
int main()
{
    string str;
    cin >> str;
    all[1].ch = 'S';
    all[2].ch = 't';
    all[3].ch = 'r';
    all[4].ch = 'i';
    all[5].ch = 'n';
    all[6].ch = 'g';
    int tot = 0;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (str[i] == all[j].ch)
            {
                all[j].t++;
                tot++;
            }
        }
    }
    while (tot)
    {
        for (int i = 1; i <= 6; i++)
        {
            if (all[i].t)
            {
                cout << all[i].ch;
                all[i].t--;
                tot--;
            }
        }
    }
    return 0;
}
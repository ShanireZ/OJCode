#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string art[10005];
int main()
{
    char ch = getchar();
    int pos = 1;
    while (ch != 'F')
    {
        if (ch == '<' && art[pos].size())
        {
            art[pos].erase(art[pos].size() - 1);
        }
        else if (ch == '.' || ch == ' ' || (ch >= 'a' && ch <= 'z'))
        {
            art[pos] += ch;
        }
        else if (ch == '\n')
        {
            pos++;
        }
        ch = getchar();
    }
    ch = getchar();
    ch = getchar();
    int st = 1, tot = 0;
    string input;
    while (ch != 'F')
    {
        if (ch == '<' && input.size())
        {
            input.erase(input.size() - 1);
        }
        else if (ch == '.' || ch == ' ' || (ch >= 'a' && ch <= 'z'))
        {
            input += ch;
        }
        else if (ch == '\n')
        {
            int sz = min(input.size(), art[st].size());
            for (int i = 0; i < sz; i++)
            {
                if (input[i] == art[st][i])
                {
                    tot++;
                }
            }
            st++;
            input.erase();
        }
        ch = getchar();
    }
    int t;
    scanf("%d", &t);
    tot = tot * 60.0 / t + 0.5;
    printf("%d", tot);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
string words[205];
int len[205];
int main()
{
    char c = cin.get();
    string s;
    int now = 1, maxl = 0, minl = 201;
    len[201] = 101;
    while (c == ' ' || c == '.' || c == ',' || isalpha(c))
    {
        if (c == ' ' || c == '.' || c == ',')
        {
            words[now] = s, len[now] = s.size();
            if (len[now] > len[maxl])
            {
                maxl = now;
            }
            if (len[now] < len[minl])
            {
                minl = now;
            }
            now++;
            s.clear();
        }
        else
        {
            s += c;
        }
        c = cin.get();
    }
    cout << words[maxl] << endl;
    cout << words[minl] << endl;
    return 0;
}
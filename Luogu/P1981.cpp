#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
string str;
int main()
{
    cin >> str;
    stringstream ss;
    int tot = 0, pre = 1, cur = 0, len = str.size();
    int start = 0, end, mode = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '*' || str[i] == '+' || i == len - 1)
        {
            end = i;
            if (i == len - 1)
            {
                end++;
            }
            ss << str.substr(start, end - start);
            ss >> cur;
            ss.clear();
            start = end + 1;
            if (str[i] == '*')
            {
                mode = 1;
                pre = (cur % 10000 * pre) % 10000;
            }
            else
            {
                if (mode == 1)
                {
                    cur = (cur % 10000 * pre) % 10000;
                    mode = 0;
                    pre = 1;
                }
                tot = (tot + cur % 10000) % 10000;
            }
        }
    }
    cout << tot;
    return 0;
}
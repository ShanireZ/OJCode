#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    char ch;
    string all;
    cin >> all;
    int start = 0, end = 1;
    int trig = 1;
    int nums = 0, words = 0;
    while (end != all.size())
    {
        if (all[end] == '+' || all[end] == '-' || all[end] == '=')
        {
            int type = 0;
            string tmp = all.substr(start, end - start);
            if (all[end - 1] >= 'a' && all[end - 1] <= 'z')
            {
                ch = all[end - 1];
                if (tmp == "-a")
                {
                    tmp = "-1";
                }
                else if (tmp == "+a" || tmp == "a")
                {
                    tmp = "1";
                }
                else
                {
                    tmp.erase(tmp.size() - 1, 1);
                }
                type = 1;
            }
            stringstream ss;
            int new_num;
            ss << tmp;
            ss >> new_num;
            if (type == 1)
            {
                words += (new_num * trig);
            }
            else
            {
                nums += (new_num * trig);
            }
            start = end;
            if (all[start] == '=')
            {
                trig = -1;
                start++;
            }
            end = start + 1;
        }
        else
        {
            end++;
        }
    }
    string tmp = all.substr(start, end - start);
    stringstream ss;
    int new_num;
    ss << tmp;
    ss >> new_num;
    nums += (new_num * trig);
    cout << ch << "=";
    if (words == 0)
    {
        cout << "0.000";
    }
    else
    {
        cout << fixed << setprecision(3) << -1.0 * nums / words;
    }
    return 0;
}
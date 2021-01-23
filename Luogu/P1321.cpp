#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int boy = 0, girl = 0;
    string str;
    cin >> str;
    str.append("."); //! 防止girl检测时下标i+3越界
    for (int i = 0; i < str.size() - 3; i++)
    {
        if (str[i] == 'b' || str[i + 1] == 'o' || str[i + 2] == 'y')
        {
            boy++;
        }
        if (str[i] == 'g' || str[i + 1] == 'i' || str[i + 2] == 'r' || str[i + 3] == 'l')
        {
            girl++;
        }
    }
    cout << boy << endl
         << girl;
    return 0;
}
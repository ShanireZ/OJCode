#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    str.insert(0, ";");
    int nums[5] = {0};
    int choose = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'c' && str[i - 1] == ';')
        {
            choose = str[i] - 'a';
        }
        if (str[i] >= 'a' && str[i] <= 'c' && str[i - 1] == '=')
        {
            nums[choose] = nums[str[i] - 'a'];
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            nums[choose] = str[i] - '0';
        }
    }
    cout << nums[0] << " " << nums[1] << " " << nums[2];
    return 0;
}
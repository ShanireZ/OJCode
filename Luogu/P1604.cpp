#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char maps[36];
int nums[2005];
int num1[2005];
int num2[2005];
int main()
{
    int b;
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        if (i < 10)
        {
            maps[i] = i + '0';
        }
        else
        {
            maps[i] = 'A' + (i - 10);
        }
    }
    string s1, s2;
    cin >> s1 >> s2;
    int pos = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < b; j++)
        {
            if (maps[j] == s1[i])
            {
                num1[pos++] = j;
                break;
            }
        }
    }
    pos = 0;
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < b; j++)
        {
            if (maps[j] == s2[i])
            {
                num2[pos++] = j;
                break;
            }
        }
    }
    int length = max(s1.size(), s2.size());
    for (int i = 0; i <= length; i++)
    {
        nums[i] += num1[i] + num2[i];
        while (nums[i] >= b)
        {
            nums[i] -= b;
            nums[i + 1]++;
        }
    }
    if (nums[length] != 0)
    {
        cout << maps[nums[length]];
    }
    for (int i = length - 1; i >= 0; i--)
    {
        cout << maps[nums[i]];
    }
    return 0;
}
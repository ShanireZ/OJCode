#include <iostream>
#include <string>
using namespace std;
int nums[10][7] = {
    //中-上中下 左上 右上 左下 右下
    {1, 0, 1, 1, 1, 1, 1}, //0
    {0, 0, 0, 0, 1, 0, 1}, //1
    {1, 1, 1, 0, 1, 1, 0}, //2
    {1, 1, 1, 0, 1, 0, 1}, //3
    {0, 1, 0, 1, 1, 0, 1}, //4
    {1, 1, 1, 1, 0, 0, 1}, //5
    {1, 1, 1, 1, 0, 1, 1}, //6
    {1, 0, 0, 0, 1, 0, 1}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 1, 0, 1}  //9
};
string all[63];
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k * 2 + 3; i++)
    {
        if (i == 0 || i == k + 1 || i == k * 2 + 2) //上中下
        {
            all[i].append(" ");
            for (int j = 0; j < s.size(); j++)
            {
                int pos = 0;
                if (i == k + 1)
                {
                    pos = 1;
                }
                else if (i == k * 2 + 2)
                {
                    pos = 2;
                }
                if (nums[s[j] - '0'][pos])
                {
                    all[i].append(k, '-');
                }
                else
                {
                    all[i].append(k, ' ');
                }
                all[i].append(3, ' ');
            }
        }
        else if (i <= k) //上半部分
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (nums[s[j] - '0'][3])
                {
                    all[i].append("|");
                }
                else
                {
                    all[i].append(" ");
                }
                all[i].append(k, ' ');
                if (nums[s[j] - '0'][4])
                {
                    all[i].append("|");
                }
                else
                {
                    all[i].append(" ");
                }
                all[i].append(" ");
            }
        }
        else //下半部分
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (nums[s[j] - '0'][5])
                {
                    all[i].append("|");
                }
                else
                {
                    all[i].append(" ");
                }
                all[i].append(k, ' ');
                if (nums[s[j] - '0'][6])
                {
                    all[i].append("|");
                }
                else
                {
                    all[i].append(" ");
                }
                all[i].append(" ");
            }
        }
    }
    for (int i = 0; i < k * 2 + 3; i++)
    {
        cout << all[i] << endl;
    }
    return 0;
}
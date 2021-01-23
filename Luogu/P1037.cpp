#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int nums[10][10];
int all[10];
int total[20001];
string mult_string(string a, string b)
{
    if (a == "0" || b == "0")
    {
        return "0";
    }
    string result;
    memset(total, 0, sizeof(total));
    for (int i = 0; i <= a.size() - 1; i++)
    {
        int pos_a = a.size() - 1 - i;
        for (int j = 0; j <= b.size() - 1; j++)
        {
            int pos_b = b.size() - 1 - j;
            total[i + j] += (a[pos_a] - '0') * (b[pos_b] - '0');
            if (total[i + j] > 9)
            {
                int next = total[i + j] / 10;
                total[i + j] %= 10;
                total[i + j + 1] += next;
            }
        }
    }
    int pos = a.size() + b.size() - 1;
    if (total[pos] == 0)
    {
        pos--;
    }
    for (int i = pos; i >= 0; i--)
    {
        result += total[i] + '0';
    }
    return result;
}
void make(int ori, int target)
{
    for (int i = 0; i < 10; i++)
    {
        if (nums[target][i] && nums[ori][i] == 0)
        {
            nums[ori][i] = 1;
            all[ori]++;
            make(ori, i);
        }
    }
}
int main()
{
    string n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < 10; i++)
    {
        nums[i][i] = 1;
        all[i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 10; j++)
        {
            if (nums[j][a] && nums[j][b] == 0)
            {
                nums[j][b] = 1;
                all[j]++;
                make(j, b);
            }
        }
    }
    string endnum = "1";
    for (int i = 0; i < n.size(); i++)
    {
        string tmp;
        tmp += char(all[n[i] - '0'] + '0');
        endnum = mult_string(endnum, tmp);
    }
    cout << endnum;
    return 0;
}
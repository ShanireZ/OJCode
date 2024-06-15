#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int id, ud, tp;
};
Node ns[15];
string bt[15], info[105][15];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = s.find(','), l = 0, pre = 0;
    while (p != string::npos)
    {
        bt[++l] = s.substr(pre, p - pre);
        pre = p + 1;
        p = s.find(',', pre);
    }
    bt[++l] = s.substr(pre);
    for (int i = 1; i < n; i++)
    {
        cin >> s;
        p = s.find(','), l = 0, pre = 0;
        while (p != string::npos)
        {
            info[i][++l] = s.substr(pre, p - pre);
            pre = p + 1;
            p = s.find(',', pre);
        }
        info[i][++l] = s.substr(pre);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        if (s[s.size() - 1] == '-')
        {
            ns[i].ud = 1; // 从大到小
        }
        s = s.substr(0, s.size() - 1);
        int id = 1;
        while (s != bt[id])
        {
            id++;
        }
        ns[i].id = id; // 当前比较元素的列号
        for (int j = 0; j < (int)info[1][id].size(); j++)
        {
            if (isalpha(info[1][id][j]))
            {
                ns[i].tp = 1; // 字符串单元格
                break;
            }
        }
    }
    for (int i = 1; i < n - 1; i++) // 冒泡排序
    {
        for (int j = n - 1; j > i; j--)
        {
            for (int k = 1; k <= m; k++)
            {
                int id = ns[k].id, tp = ns[k].tp, ud = ns[k].ud;
                if (info[j - 1][id] == info[j][id])
                {
                    continue;
                }
                if (tp == 0)
                {
                    int a = stoi(info[j - 1][id]), b = stoi(info[j][id]);
                    if ((ud == 0 && a > b) || (ud == 1 && a < b))
                    {
                        swap(info[j - 1], info[j]);
                    }
                }
                else
                {
                    string a = info[j - 1][id], b = info[j][id];
                    if ((ud == 0 && a > b) || (ud == 1 && a < b))
                    {
                        swap(info[j - 1], info[j]);
                    }
                }
                break;
            }
        }
    }
    for (int i = 1; i <= l; i++)
    {
        cout << bt[i];
        if (i < l)
        {
            cout << ',';
        }
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            cout << info[i][j];
            if (j < l)
            {
                cout << ',';
            }
        }
        cout << endl;
    }
    return 0;
}
// TAG: 大模拟 字符串
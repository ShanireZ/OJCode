#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Node
{
    int data, op, id;
    bool operator<(const Node &oth) const
    {
        if (op == oth.op)
        {
            return id < oth.id;
        }
        return op < oth.op;
    }
};
vector<Node> ot[3];
map<int, int> mp;
int n, ans[5005], mth[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int addData(int data)
{
    int year = data / 10000, month = data / 100 % 100, day = data % 100 + 1;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        mth[2] = 29;
    }
    else
    {
        mth[2] = 28;
    }
    if (day > mth[month])
    {
        day = 1, month++;
    }
    if (month > 12)
    {
        year++, month = 1;
    }
    return year * 10000 + month * 100 + day;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch1, ch2;
        int num;
        cin >> ch1 >> num >> ch2;
        int x1 = (ch1 == 'O' ? 0 : (ch1 == 'C' ? 1 : 2));
        int x2 = (ch2 == 'M' ? 0 : (ch2 == 'A' ? 1 : 2));
        ot[x2].emplace_back(Node{num, x1, i});
    }
    for (int t = 0; t < 3; t++)
    {
        sort(ot[t].begin(), ot[t].end());
        mp.clear();
        for (Node x : ot[t])
        {
            while (mp[x.data])
            {
                x.data = addData(x.data);
            }
            mp[x.data] = 1, ans[x.id] = x.data;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
struct Stu
{
    int ch, ma, en, score;
    string name;
};
Stu stu[1005];
bool cmp(Stu a, Stu b)
{
    return a.name < b.name;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].name >> stu[i].ch >> stu[i].ma >> stu[i].en;
        stu[i].score = stu[i].ch + stu[i].ma + stu[i].en;
    }
    sort(stu + 1, stu + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ch = abs(stu[i].ch - stu[j].ch);
            int ma = abs(stu[i].ma - stu[j].ma);
            int en = abs(stu[i].en - stu[j].en);
            int score = abs(stu[i].score - stu[j].score);
            if (score <= 10 && ch <= 5 && ma <= 5 && en <= 5)
            {
                cout << stu[i].name << " " << stu[j].name << endl;
            }
        }
    }
    return 0;
}
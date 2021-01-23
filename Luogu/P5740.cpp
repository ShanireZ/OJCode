#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Stu
{
    int ch, ma, en, id, score;
    string name;
};
Stu stu[1005];
bool cmp(Stu a, Stu b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    return a.score > b.score;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stu[i].id = i;
        cin >> stu[i].name >> stu[i].ch >> stu[i].ma >> stu[i].en;
        stu[i].score = stu[i].ch + stu[i].ma + stu[i].en;
    }
    sort(stu + 1, stu + 1 + n, cmp);
    cout << stu[1].name << " " << stu[1].ch << " " << stu[1].ma << " " << stu[1].en << endl;
    return 0;
}
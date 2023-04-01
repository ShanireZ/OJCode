#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct STU
{
    string name, id;
    int score;
    bool operator<(const STU &oth) const
    {
        return score > oth.score;
    }
};
STU all[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i].name >> all[i].id >> all[i].score;
    }
    sort(all + 1, all + 1 + n);
    cout << all[1].name << " " << all[1].id << "\n";
    cout << all[n].name << " " << all[n].id << "\n";
    return 0;
}
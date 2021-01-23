#include <iostream>
using namespace std;
struct Stu
{
    int left, right;
};
Stu all[100005];
int check[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            all[i].right = k;
            all[i].left = all[k].left;
            all[all[k].left].right = i;
            all[k].left = i;
        }
        else
        {
            all[i].left = k;
            all[i].right = all[k].right;
            all[all[k].right].left = i;
            all[k].right = i;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int pos;
        cin >> pos;
        if (check[pos] == 0)
        {
            all[all[pos].left].right = all[pos].right;
            all[all[pos].right].left = all[pos].left;
            check[pos] = 1;
        }
    }
    for (int i = all[0].right; i != 0; i = all[i].right)
    {
        cout << i << " ";
    }
    return 0;
}
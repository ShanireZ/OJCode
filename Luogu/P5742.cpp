#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
struct Stu
{
    int id, study, bound;
    double tot;
    void make()
    {
        tot = 0.7 * study + 0.3 * bound;
    }
    void check()
    {
        if (study + bound > 140 && tot >= 80)
        {
            cout << "Excellent" << endl;
        }
        else
        {
            cout << "Not excellent" << endl;
        }
    }
};
Stu stu[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].id >> stu[i].study >> stu[i].bound;
        stu[i].make();
        stu[i].check();
    }
    return 0;
}